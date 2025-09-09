#include <iostream>
#include "parse.hpp"
using namespace std;
int main (int argc, char* argv[])
{
    Parse myParser;
    Param myParameters;
    bool debugMode = false;
    bool exit = false;
    char* inputLine;
    if (argc > 1) {
        if (argv[1] == "-Debug"){
            debugMode = true;
        }
    }
    while(exit == false) {
        cout << "myshell> ";
        cin.getline(inputLine, 1024);
    }
    if (inputLine == "exit") {
        exit = true;
    }
    else {
        myParser.getUserInput(inputLine, myParameters);
        if (debugMode == true){
            myParameters.printParams();
        }
    }
    return 0;
}