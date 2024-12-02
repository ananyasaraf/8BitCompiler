#include "E:\Compiler\My_Compiler\codegen.h"

void generateAssembly(const std::shared_ptr<ASTNode>& root) {
    if (!root) return;

    // Simple example for generating assembly
    if (root->token.type == TokenType::Number) {
        std::cout << "PUSH " << root->token.text << std::endl;
    } else if (root->token.type == TokenType::Identifier) {
        std::cout << "LOAD " << root->token.text << std::endl;
    }

    for (const auto& child : root->children) {
        generateAssembly(child);
    }
}
