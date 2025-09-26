#include <iostream>
#include <cstring>
#include "parse.hpp"
#include <unistd.h>
#include <cstdio>
#include <sys/wait.h>  // Add this include
using namespace std;
int main (int argc, char *argv[])
{
    Parse myParser;
    Param myParameters;
    bool debugMode = false;
    bool exit = false;
    char* inputLine = new char[1024];
    if (argc > 1) {
        if (strcmp(argv[1], "-Debug") == 0) {
            debugMode = true;
        }
    }
    while(exit == false) {
        cout << "$$$ ";
        cin.getline(inputLine, 1024);
    
        if (strcmp(inputLine, "exit") == 0) {
            // Clean up all background processes before exiting
            cout << "Waiting for background processes to finish..." << endl;
            while (waitpid(-1, nullptr, WNOHANG) > 0) {
                cout << "Cleaned up background process" << endl;
            }
            exit = true;
        }
        else {
            myParser.getUserInput(inputLine, myParameters);
            if (debugMode == true){
                myParameters.printParams();
            }
            //execute command
            pid_t pid = fork();
            if (pid < 0) {
                cerr << "Fork failed." << endl;
                return 1;
            }
            else if (pid == 0) {
                //child process running
                if (myParameters.getInputRedirect() != nullptr){
                    if (freopen(myParameters.getInputRedirect(), "r", stdin) == nullptr) {
                        cerr << "Error: cannot open input file: " << myParameters.getInputRedirect() << endl;
                        std::exit(1);
                    }
                }
                if (myParameters.getOutputRedirect() != nullptr){
                    if (freopen(myParameters.getOutputRedirect(), "w", stdout) == nullptr){
                        cerr << "Error: cannot open output file: " << myParameters.getOutputRedirect() << endl;
                        std::exit(1);
                    }
                }
                execvp(myParameters.getArgumentVector()[0], myParameters.getArgumentVector());
                cerr << "Execvp failed for command: " << myParameters.getArgumentVector()[0] << endl;
                std::exit(1); // Exit child process if execvp fails
            }
            else {
        // Parent process
        if (myParameters.getBackground() == 1) {
            // Background process - don't wait
            std::cout << "Background process started with PID: " << pid << std::endl;
        } else {
            // Foreground process - wait for completion
            int status;
            waitpid(pid, &status, 0); 
            std::cout << "Child process finished with status: " << status << std::endl;
        }
    }
        }
    }
    delete [] inputLine;
    return 0;
}