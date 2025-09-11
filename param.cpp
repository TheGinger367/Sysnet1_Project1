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
    if (argumentCount < MAXARGS) {
    argumentVector[argumentCount] = new char[strlen(argumentVectorArg) + 1];
    strcpy(argumentVector[argumentCount], argumentVectorArg);
    argumentCount += 1;
    }
    else {
    std::cerr << "Too many arguments!\n";
}
}
//When the line is parsed, the first three tokens are not special, so they must be placed in argumentVector[0],
//argumentVector[1], and argumentVector[2] accordingly. When the fourth token is extracted, it is
//identified as an input redirection because of the beginning character (' <'). The characters following the redirection
//indicator form the name of the file from which input must be redirected. The name of the input file ("four") must be
//stored in inputRedirect. Similarly, the beginning character ('>') of the fifth token identifies output redirection,
//and the characters following the redirect character specify the name of the file to which output must be written.
//The name of the output file ("five") must be stored in outputRedirect.