/* 控制台 交互模式 */

#include <iostream>
#include "lexer.hpp"

const string PROMPT = ">> ";

void start() {
    string input;
    cout << PROMPT;
    while (getline(cin, input)) {
        Lexer *l = new_lex(input);
        while (l->ch != 0) {
            token tok = next_token(l);
            cout << "type: " << tok.type << ", literal: " << tok.Literal << endl;
        }
        cout << PROMPT;
    }
}

#ifndef FIREFLY_INTERPRETER_REPL_HPP
#define FIREFLY_INTERPRETER_REPL_HPP

#endif //FIREFLY_INTERPRETER_REPL_HPP
