#ifndef __LEXER_H
#define __LEXER_H
#include <string>
#include <vector>

enum class TokenType {
    Identifier,
    Integer,
    Keyword,
    Equal,
    LeftParen,
    String,
    Semicolon,
    EndOfFile,
    Unknown
};
struct Token {
    TokenType type;
    std::string value;
};

class Lexer
{
    public:
    Lexer(std::string sourceCode)
    {
        source = sourceCode;
        cursor = 0;
        size = sourceCode.length();
        current = sourceCode.at(cursor);
    }

    char advance()
    {
        if (cursor < size) {
            char temp = current;
            cursor++;
            current = (cursor < size) ? source[cursor] : '\0';
        } 
        else 
        {
            return '\0';
        }
    }

    void checkAndSkip()
    {
        while (current == ' ' || current == '\n' || current == '\t' || current == '\r') advance();
    }

    std::vector <Token *> tokenize()
    {
        std::vector <Token *> tokens;
        bool notEOF = true;
        while (cursor < size && notEOF)
        {
            checkAndSkip();
            if (isalpha(current) || current = "_")
            {
                tokens.push_back(tokenizeID());
                continue;
            }
        }
    }

    char peek(int offset = 0)
    {
        if (cursor + offset < size) return source[cursor + offset]; 
        else return '\0';
    }
    private:
    std::string source;
    int cursor;
    int size;
    char current;
};

#endif