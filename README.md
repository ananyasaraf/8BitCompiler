                  # SimpleLang Compiler for 8-Bit CPU
                  
                  ## Introduction
                  SimpleLang is a minimalistic high-level language designed to run on an 8-bit CPU. This project aims to create a compiler that translates SimpleLang code into assembly code for an 8-bit CPU. The language includes basic constructs such as variable declarations, assignments, arithmetic operations, and conditional statements.
                  
                  ## Language Constructs
                  ### Variable Declaration
                  - **Syntax**: `int variable_name;`
                  - **Example**: `int a;`
                  
                  ### Assignment
                  - **Syntax**: `variable = expression;`
                  - **Example**: `a = b + c;`
                  
                  ### Arithmetic Operations
                  - **Supported operators**: `+`, `-`
                  - **Example**: `a = b - c;`
                  
                  ### Conditionals
                  - **Syntax**: `if (condition) { statements }`
                  - **Example**: `if (a == b) { a = a + 1; }`
                  
                  ## Example Program in SimpleLang
                  ```plaintext
                  // Variable declaration
                  int a;
                  int b;
                  int c;
                  
                  // Assignment
                  a = 10;
                  b = 20;
                  c = a + b;
                  
                  // Conditional
                  if (c == 30) {
                    c = c + 1;
                  }

Structure of Project
                My_Compiler/
                ├── lexer.h
                ├── lexer.cpp
                ├── parser.h
                ├── parser.cpp
                ├── codegen.h
                ├── codegen.cpp
                ├── main.cpp
                ├── input.txt
                └── README.md
 Setup and Usage
        Prerequisites
            A C++ compiler (e.g., g++)
            Git

Cloning the Repository

            sh
            git clone https://github.com/ananyasaraf/8BitCompiler.git
            cd 8BitCompiler
Building the Compiler
            sh
            g++ -o simplelang_compiler main.cpp lexer.cpp parser.cpp codegen.cpp 
