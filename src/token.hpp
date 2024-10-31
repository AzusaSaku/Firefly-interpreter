/* 定义词法单元 */

#include <string>
#include <map>

using namespace std;

// 词法单元类型
enum token_type {
    ILLEGAL, END,
    IDENT, INT, // 标识符
    ASSIGN, PLUS, MINUS, ASTERISK, SLASH, BANG, LT, GT, // 运算符 -> = + - * / ! < >
    COMMA, SEMICOLON, // 分隔符 -> , ;
    LPAREN, RPAREN, LBRACE, RBRACE, // 括号 -> ( ) { }
    EQ, NOT_EQ, // 分支比较 -> == !=
    FUNC, VAR, TRUE, FALSE, IF, ELSE, RETURN // 关键字 -> func var true false if else return
};

struct token {
    string Literal;
    token_type type;
};

// 关键字
map<string, token_type> keywords = {
        {"func",   FUNC},
        {"var",    VAR},
        {"true",   TRUE},
        {"false",  FALSE},
        {"if",     IF},
        {"else",   ELSE},
        {"return", RETURN}
};

token_type lookup_ident(const string &ident) {
    if (keywords.find(ident) != keywords.end()) {
        return keywords[ident];
    }
    return IDENT;
}

#ifndef FIREFLY_INTERPRETER_TOKEN_H
#define FIREFLY_INTERPRETER_TOKEN_H

#endif //FIREFLY_INTERPRETER_TOKEN_H
