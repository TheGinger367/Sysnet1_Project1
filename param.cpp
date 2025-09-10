#include <iostream>
#include "param.hpp"

void Param::printParams(){
    std::cout << "Input Redirect: " << (inputRedirect ? inputRedirect : "NULL") << std::endl;
    std::cout << "Output Redirect: " << (outputRedirect ? outputRedirect : "NULL") << std::endl;
    std::cout << "Background: " << background << std::endl;
    std::cout << "Argument Count: " << argumentCount << std::endl;
    std::cout << "Argument Vector: ";
    for(int i = 0; i < argumentCount; i++) {
        std::cout << argumentVector[i] << " ";
    }
    std::cout << std::endl;
}

char Param::getInputRedirect(){    return inputRedirect ? *inputRedirect : '\0';}
void Param::setInputRedirect(char *inputRedirect){this->inputRedirect = inputRedirect;}

char Param::getOutputRedirect(){return outputRedirect ? *outputRedirect : '\0';}
void Param::setOutputRedirect(char *outputRedirect){ this->outputRedirect = outputRedirect;}

int Param::getBackground(){return background;}
void Param::setBackground(int background){this->background = background;}
        
int Param::getArgumentCount(){return argumentCount;}
void Param::setArgumentCount(int argc){
    argumentCount = argc;
}

void Param::setArgumentVector(char *argumentVectorArg){
    argumentVector[argumentCount] = new char[strlen(argumentVectorArg) + 1];
    strcpy(argumentVector[argumentCount], argumentVectorArg);
    argumentCount += 1;
}
//When the line is parsed, the first three tokens are not special, so they must be placed in argumentVector[0],
//argumentVector[1], and argumentVector[2] accordingly. When the fourth token is extracted, it is
//identified as an input redirection because of the beginning character (' <'). The characters following the redirection
//indicator form the name of the file from which input must be redirected. The name of the input file ("four") must be
//stored in inputRedirect. Similarly, the beginning character ('>') of the fifth token identifies output redirection,
//and the characters following the redirect character specify the name of the file to which output must be written.
//The name of the output file ("five") must be stored in outputRedirect.

// void Param::getUserInput(char * userInput){
//     argumentCount = 0;
//     inputRedirect = nullptr;
//     outputRedirect = nullptr;
//     background = 0;

//     const char* delim = " \t";
//     char* token = strtok(userInput, delim);
//     while (token != nullptr) {

//         //check for input
//         if(token[0] == '<') {
//             if(token[1] == '\0') {
//                 std::cerr << "Syntax error: missing input filename after '<'\n";
//                 return;
//             }
//             else {
//                 inputRedirect = token + 1;
//             }
//         }
//         //check output
//         if(token[0] == '>') {
//             if (token[1] == '\0'){
//                 std::cerr << "Syntax error: missing output filename after '>'\n";
//                 return;
//             }
//             else{
//                 outputRedirect = token + 1;
//             }
//         }
//             // Check for backgrounding "&"
//         else if (token[0] == '&' && token[1] == '\0') {
//         // '&' must be last
//             token = strtok(nullptr, delim);
//             if (token != nullptr) {
//                 std::cerr << "Syntax error: '&' must appear at the end of the command\n";
//                 return;
//             }
//             background = true;
//             break; // no more parsing
//         }
//         else {
//             if (argumentCount >= MAXARGS) {
//                 std::cerr << "Error: too many arguments (max " << MAXARGS << ")\n";
//                 return;
//             }
//             argumentVector[argumentCount++] = token;
//         }
//         token = strtok(nullptr, delim);
//     }
// }
    /* //needs to be fixed
    if (strtok(userInput, " ") != NULL){
        argumentVector[0] = strtok(userInput, " ");
        for(int i = 1; token != NULL; i++) {
            token = strtok(NULL, " ");
            argumentVector[i] = token;
        }
    }

    else if (strtok(userInput, "\t") != NULL){
        argumentVector[0] = strtok(userInput, "\t");
        for(int j = i; token != NULL; j++) {
            token = strtok(NULL, " ");
            argumentVector[j] = token;
        }
    }

    if (strtok(userInput, " ") != NULL){
        argumentVector[0] = strtok(userInput, " ");
    }
    else if (strtok(userInput, "\t") != NULL){
        argumentVector[0] = strtok(userInput, "\t");
    }
    for(int i = 1; token != NULL; i++) {
        token = strtok(NULL, " ");
        if (token != NULL){
            argumentVector[i] = token;
        }
        else{
            argumentVector[i] = NULL;
        }
}
    
    inputRedirect = strtok(userInput, "<");
    outputRedirect = strtok(userInput, ">");
} */