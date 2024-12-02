#include "Lexer.h"
#include <cctype>
#include <cstring>

Lexer::Lexer(const std::string& filename) {
    inputStream.open(filename);
    if (!inputStream) {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
        exit(1);
    }
}

Token Lexer::getNextToken() {
    Token token;
    char currentChar;

    while (inputStream.get(currentChar)) {
        if (std::isspace(currentChar)) {
            continue;
        }

        if (std::isalpha(currentChar)) {
            int tokenLength = 0;
            token.text[tokenLength++] = currentChar;

            while (inputStream.get(currentChar) && std::isalnum(currentChar)) {
                if (tokenLength < MAX_TOKEN_LEN - 1) {
                    token.text[tokenLength++] = currentChar;
                }
            }

            inputStream.unget();
            token.text[tokenLength] = '\0';

            if (strcmp(token.text, "int") == 0) {
                token.type = TokenType::Int;
            } else if (strcmp(token.text, "if") == 0) {
                token.type = TokenType::If;
            } else {
                token.type = TokenType::Identifier;
            }
            return token;
        }

        if (std::isdigit(currentChar)) {
            int tokenLength = 0;
            token.text[tokenLength++] = currentChar;

            while (inputStream.get(currentChar) && std::isdigit(currentChar)) {
                if (tokenLength < MAX_TOKEN_LEN - 1) {
                    token.text[tokenLength++] = currentChar;
                }
            }

            inputStream.unget();
            token.text[tokenLength] = '\0';
            token.type = TokenType::Number;
            return token;
        }

        token.text[0] = currentChar;
        token.text[1] = '\0';

        switch (currentChar) {
            case '=': token.type = TokenType::Assign; return token;
            case '+': token.type = TokenType::Plus; return token;
            case '-': token.type = TokenType::Minus; return token;
            case '{': token.type = TokenType::LeftBrace; return token;
            case '}': token.type = TokenType::RightBrace; return token;
            case ';': token.type = TokenType::Semicolon; return token;
            default:  token.type = TokenType::Unknown; return token;
        }
    }

    token.type = TokenType::EndOfFile;
    token.text[0] = '\0';
    return token;
}
