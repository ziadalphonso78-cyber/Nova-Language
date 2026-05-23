#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "headers/lexer.hpp"

int main(int argc, char ** argv) {
    if (argc < 2) 
    {
        std::cout << "Please Supply Source File" << std::endl;
        exit(1);
    }
    std::cout << "Reading From Source File " << argv[1] << std::endl;

    std::ifstream sourceFileStream (argv[1]);

    std::stringstream buffer;

    char temp;

    while (sourceFileStream.get(temp)) buffer << temp;

    std::string sourceCode = buffer.str();

    std::cout << "This is the source code\n" << std::endl << sourceCode << std::endl;

    Lexer lexer(sourceCode);

    std::vector <Token *> tokens = lexer.tokenize();

    std::cout << "End Of Program" << std::endl;
    return 0;
}