# Language Processor
A collection of compiler and language processing tools implemented in **C**, **Lex**, and **Yacc**.

## Overview
This repository contains modular implementations of the core phases of a compiler/language processor, built as a learning/academic reference.

## Repository Structure
```
Language-_Processor/
├── lexicl_analyser/        # Lexical analysis (tokenizer)
├── parser/                 # Syntax analysis (top-down/recursive descent)
├── shift_parser/           # Shift-reduce (bottom-up) parsing
├── lex_yacc_tool/          # Integrated lexer + parser using Lex & Yacc
├── if_else_ladder/         # Intermediate code generation for if-else constructs
├── three_address_code/     # Three-address code (TAC) generation
├── codeoptimisation/       # Code optimization passes
└── 3ac_to_8085 complier/   # TAC to Intel 8085 assembly code generation
```

---

## Modules
1. Lexical Analyser (`lexicl_analyser/`)
2. Parser (`parser/`)
3. Shift Parser (`shift_parser/`)
4. Lex & Yacc Tool (`lex_yacc_tool/`)
5. If-Else Ladder (`if_else_ladder/`)
6. Three Address Code (`three_address_code/`)
7. Code Optimisation (`codeoptimisation/`)
8. 3AC to 8085 Compiler (`3ac_to_8085 complier/`)


## Languages & Tools
| Language/Tool | Usage |
|---|---|
| C | Core implementations |
| Lex  | Lexer specification and generation |
| Yacc | Parser specification and generation |


## Getting Started
### Prerequisites

- GCC (C compiler)
- Flex (fast lexical analyser generator)
- Bison (GNU Yacc-compatible parser generator)

Install on Debian/Ubuntu:
```bash
sudo apt-get install gcc flex bison
```

### Building a Module

Navigate into any module directory and compile the C files:
```bash
cd lexicl_analyser
gcc lexical_analyser.c -o lexical_analyser
./lexical_analyser
```

For Lex/Yacc-based modules:
```bash
cd lex_yacc_tool
lex scanner.l          # generates lex.yy.c
yacc -d parser.y       # generates y.tab.c and y.tab.h
gcc lex.yy.c y.tab.c -o parser -lfl
./parser
```


---

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

---

## License

This project is licensed under standard open source terms. See the repository for details.
