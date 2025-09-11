
#include "parse.hpp"
#include <iostream>

void Parse::getUserInput(char *userInput, Param& paramObj){
    paramObj.setArgumentCount(0);
    paramObj.setInputRedirect(nullptr);
    paramObj.setOutputRedirect(nullptr);
    paramObj.setBackground(0);
    //this is the only thing im confused about. Its taking ' ' and '\t' as delimiters or ' \t' and a delimiter?
    //it might do that but once we get the print statement set up we should be able to see that and fix it
    const char* delim = " \t";
    char* token = strtok(userInput, delim);
    while (token != nullptr) {

        //check for input
        if(token[0] == '<') {
            if(token[1] == '\0') {
                std::cerr << "Syntax error: missing input filename after '<'\n";
                return;
            }
            else {
                paramObj.setInputRedirect(token + 1);
            }
        }
        //check output
        if(token[0] == '>') {
            if (token[1] == '\0'){
                std::cerr << "Syntax error: missing output filename after '>'\n";
                return;
            }
            else{
                paramObj.setOutputRedirect(token + 1);
            }
        }
            // Check for backgrounding "&"
        else if (token[0] == '&' && token[1] == '\0') {
        // '&' must be last
            token = strtok(nullptr, delim);
            if (token != nullptr) {
                std::cerr << "Syntax error: '&' must appear at the end of the command\n";
                return;
            }
            paramObj.setBackground(1);
            break; // no more parsing
        }
        else {
            if (paramObj.getArgumentCount() >= MAXARGS) {
                std::cerr << "Error: too many arguments (max " << MAXARGS << ")\n";
                return;
            }
            paramObj.setArgumentVector(token);
        }
        token = strtok(nullptr, delim);
    }
}