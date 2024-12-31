/* 控制台 交互模式 */

#ifndef FIREFLY_INTERPRETER_REPL_HPP
#define FIREFLY_INTERPRETER_REPL_HPP

#include "lexer.hpp"
#include "parser.hpp"
#include <iostream>

const string PROMPT = ">> ";

void start() {
    string input;
    cout << PROMPT;
    while (getline(cin, input)) {
        Lexer *l = new_lex(input);
        auto *p = new Parser(l);

        Program *program = p->parse_program();
        cout << program->token_literal() << endl;
        cout << PROMPT;
    }
}

#endif //FIREFLY_INTERPRETER_REPL_HPP
