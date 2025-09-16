#include <iostream>
#include <cstring>
#include "parse.hpp"
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
        cout << "myshell> ";
        cin.getline(inputLine, 1024);
    
        if (strcmp(inputLine, "exit") == 0) {
            exit = true;
            /* terminates the shell; all child processes must be terminated for the shell to close avoiding creation of zombie processes */
        }
        else {
            myParser.getUserInput(inputLine, myParameters);
            if (debugMode == true){
                myParameters.printParams();
            }
            
            if (argumentVector[0] == "cat"){
                if (!background){
                    /* displays the source code of the program on the screen */
                }
                else{
                    if (argumentVector[1] == NULL){
                        /* displays the source code of the program on the screen as below except the output will be displayed in the background causing the prompt of the shell to be mixed with the output of the file*/
                    }
                    else{
                        /* displays the content of the text file testfile.txt on the screen in the background */
                    }
                }
            }
            else if (argumentVector[0] == "ls" && argumentVector[1] == "-l"){
                if (outputRedirect == NULL){
                    /* shows a listing of files in the current directory */
                }
                else{
                    /* writes a listing of files into the text file testfile.txt */
                }
            }
            else if (argumentVector[0] == "./slow" && background){
                /* runs the program slow from the current working directory in the background */
            }
            else if (argumentVector[0] == "grep" && argumentVector[1] == "-i" && argumentVector[2] == "shell"){
                /* list many lines containing the word shell in the previous file */
            }
            else {
                /* unknown command */
            }   
        }
    }
    delete [] inputLine;
    return 0;
}

//ls –l                       shows a listing of files in the current directory
//ls –l >testfile.txt         writes a listing of files into the text file testfile.txt
//grep –i shell testfile.txt  list many lines containing the word shell in the previous file
//cat <myshell.cpp            displays the source code of the program on the screen
//cat <myshell.cpp &          as above except the output will be displayed in the background causing  
//                            the prompt of the shell to be mixed with the output of the file
//cat testfile.txt &          displays the content of the text file testfile.txt on the screen in the
//                            background
//./slow &                    runs the program slow from the current working directory in the
//                            background
//exit                        terminates the shell; all child processes must be terminated for the shell
//                            to close avoiding creation of zombie processes