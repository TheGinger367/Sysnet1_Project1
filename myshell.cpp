#include <iostream>
#include <cstring>
#include "parse.hpp"

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
        std::cin.getline(inputLine, 1024);
    
        if (strcmp(inputLine, "exit") == 0) {
            exit = true;
            /* terminates the shell; all child processes must be terminated for the shell to close avoiding creation of zombie processes */
        }
        else {
            myParser.getUserInput(inputLine, myParameters);
            if (debugMode == true){
                myParameters.printParams();
            }
            
            if (argumentVector[0] == "cat" && inputRedirect != NULL){
                if (!background){
                    /* displays the source code of the program on the screen */
                    std::ifstream file(inputRedirect);

                    if (file.is_open())
                        std::cout << file.rdbuf();
                }
                else{
                    if (argumentVector[1] == NULL){
                        /* displays the source code of the program on the screen as above except the output will be displayed in the background causing the prompt of the shell to be mixed with the output of the file*/
                    }
                    else{
                        /* displays the content of the text file testfile.txt on the screen in the background */
                    }
                }
            }
            else if (argumentVector[0] == "ls" && argumentVector[1] == "-l"){
                if (outputRedirect == NULL){
                    /* shows a listing of files in the current directory */
                    //opendir, readdir, printf, and closedir?
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
                //What does this mean? what is the previous file?
            }
            else {
                /* unknown command */
                std::cout << "The command you have entered is unknown, make sure the command is typed correctly and includes all nessisary arguments." << std::endl;
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