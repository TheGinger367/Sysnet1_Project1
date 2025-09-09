#include <iostream>
#include "param.hpp"

Param::printParams(){
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

char Param::getInputRedirect(){return *inputRedirect;}
void Param::setInputRedirect(char *inputRedirect){inputRedirect = inputRedirect;}

char Param::getOutputRedirect(){return outputRedirect;}
void Param::setOutputRedirect(){}

int Param::getBackground(){return background;}
void Param::setBackground(){}
        
int Param::getArgumentCount(){return argumentCount;}
void Param::setArgumentCount(){}

//When the line is parsed, the first three tokens are not special, so they must be placed in argumentVector[0],
//argumentVector[1], and argumentVector[2] accordingly. When the fourth token is extracted, it is
//identified as an input redirection because of the beginning character (' <'). The characters following the redirection
//indicator form the name of the file from which input must be redirected. The name of the input file ("four") must be
//stored in inputRedirect. Similarly, the beginning character ('>') of the fifth token identifies output redirection,
//and the characters following the redirect character specify the name of the file to which output must be written.
//The name of the output file ("five") must be stored in outputRedirect.

void Param::getUserInput(){
    char userInput[1024];
    char token[1024] = NULL;

    std::cin >> std::ws;
    std::cin.getline(cin, userInput);

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
}