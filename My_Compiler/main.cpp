#include "Lexer.h"
#include "Parser.h"
#include "E:\Compiler\My_Compiler\codegen.h"

int main() {
    // Lexer
    Lexer lexer("test.txt");
    std::vector<Token> tokens;

    Token token;
    while ((token = lexer.getNextToken()).type != TokenType::EndOfFile) {
        tokens.push_back(token);
    }

    // Parser
    Parser parser(tokens);
    auto astRoot = parser.parseExpression();

    // Code Generator
    generateAssembly(astRoot);

    return 0;
}
