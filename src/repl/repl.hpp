/* 控制台 交互模式 */

#include "../lexer/lexer.hpp"
#include <iostream>

const string PROMPT = ">> ";

void start() {
    string input;
    cout << PROMPT;
    while (getline(cin, input)) {
        Lexer *l = new_lex(input);
        while (l->ch != 0) {
            Token tok = next_token(l);
            cout << "type: " << tok.type << ", literal: " << tok.Literal << endl;
        }
        cout << PROMPT;
    }
}

#ifndef FIREFLY_INTERPRETER_REPL_HPP
#define FIREFLY_INTERPRETER_REPL_HPP

#endif //FIREFLY_INTERPRETER_REPL_HPP
