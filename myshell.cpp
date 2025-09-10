#include <iostream>
#include "parse.hpp"
using namespace std;
int main (int argc, char* argv[])
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
    }
    else {
        myParser.getUserInput(inputLine, myParameters);
        if (debugMode == true){
            myParameters.printParams();
        }
    }
    }
    delete [] inputLine;
    return 0;
}