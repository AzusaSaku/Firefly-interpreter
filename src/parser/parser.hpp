/* 语法分析器 */

#include "../lexer/lexer.hpp"
#include "../ast/ast.hpp"

class Parser {
public:
    Lexer *l;
    Token cur_token;
    Token peek_token;

    explicit Parser(Lexer *lexer) : l(lexer) {
        next_token();
        next_token();
    }

    void next_token() {
        cur_token = peek_token;
        peek_token = l->next_token();
    }

    Program *parse_program() {
        // TODO
    }
};

void parse_program() {
    program = new Program();
};

#ifndef FIREFLY_INTERPRETER_PARSER_HPP
#define FIREFLY_INTERPRETER_PARSER_HPP

#endif //FIREFLY_INTERPRETER_PARSER_HPP
