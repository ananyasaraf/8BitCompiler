#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"
#include <vector>
#include <memory>

// Abstract Syntax Tree Node
struct ASTNode {
    Token token;
    std::vector<std::shared_ptr<ASTNode>> children;
};

// Parser class
class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens);
    std::shared_ptr<ASTNode> parseExpression();

private:
    std::vector<Token> tokens;
    size_t currentIndex;

    Token peek();
    Token consume();
};

#endif // PARSER_H
