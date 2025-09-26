#include <cstring>
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

char* Param::getInputRedirect(){    return inputRedirect ? inputRedirect : nullptr;}
void Param::setInputRedirect(char *inputRedirect){this->inputRedirect = inputRedirect;}

char* Param::getOutputRedirect(){return outputRedirect ? outputRedirect : nullptr;}
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
char** Param::getArgumentVector()
{
    return argumentVector;
}