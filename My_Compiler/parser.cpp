#include "Parser.h"

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens), currentIndex(0) {}

Token Parser::peek() {
    if (currentIndex < tokens.size()) {
        return tokens[currentIndex];
    }
    return Token{TokenType::EndOfFile, ""};
}

Token Parser::consume() {
    if (currentIndex < tokens.size()) {
        return tokens[currentIndex++];
    }
    return Token{TokenType::EndOfFile, ""};
}

std::shared_ptr<ASTNode> Parser::parseExpression() {
    auto node = std::make_shared<ASTNode>();
    Token token = consume();

    node->token = token;
    if (token.type == TokenType::Number || token.type == TokenType::Identifier) {
        return node;
    }

    return nullptr; // Simple placeholder for now
}
