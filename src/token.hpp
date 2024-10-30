/* 定义词法单元 */

#include <string>
#include <map>

using namespace std;

enum token_type {
    TK_ILLEGAL, TK_EOF,
    TK_IDENT, TK_INT, // 标识符
    TK_ASSIGN, TK_PLUS, // 运算符
    TK_COMMA, TK_SEMICOLON, // 分隔符
    TK_LPAREN, TK_RPAREN, TK_LBRACE, TK_RBRACE, // 括号
    TK_FUNC, TK_VAR // 关键字
};

struct token {
    string Literal;
    token_type type;
};

map<string, token_type> keywords = {
        {"func", TK_FUNC},
        {"var", TK_VAR}
};

token_type lookup_ident(const string& ident) {
    if (keywords.find(ident) != keywords.end()) {
        return keywords[ident];
    }
    return TK_IDENT;
}

#ifndef FIREFLY_INTERPRETER_TOKEN_H
#define FIREFLY_INTERPRETER_TOKEN_H

#endif //FIREFLY_INTERPRETER_TOKEN_H
