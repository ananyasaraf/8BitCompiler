#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include "Parser.h"
#include <iostream>

void generateAssembly(const std::shared_ptr<ASTNode>& root);

#endif // CODE_GENERATOR_H
