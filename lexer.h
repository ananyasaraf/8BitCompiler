#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define MAX_TOKEN_LEN 100

// Token types
enum class TokenType {
    Int, Identifier, Number, Assign,
    Plus, Minus, If, Equal,
    LeftBrace, RightBrace, Semicolon,
    Unknown, EndOfFile
};

// Token structure
struct Token {
    TokenType type;
    char text[MAX_TOKEN_LEN];
};

// Lexer class
class Lexer {
public:
    explicit Lexer(const std::string& filename);
    Token getNextToken();

private:
    std::ifstream inputStream;
};

#endif // LEXER_H
