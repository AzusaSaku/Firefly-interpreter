/* 定义词法单元 */

#ifndef FIREFLY_INTERPRETER_TOKEN_H
#define FIREFLY_INTERPRETER_TOKEN_H

#include <string>
#include <map>
#include "include/magic_enum.hpp"

using namespace std;

// 词法单元类型
enum class TokenType {
    ILLEGAL = 0, END,
    IDENT, INT, // 标识符
    ASSIGN, PLUS, MINUS, ASTERISK, SLASH, BANG, LT, GT, // 运算符 -> = + - * / ! < >
    COMMA, SEMICOLON, // 分隔符 -> , ;
    LPAREN, RPAREN, LBRACE, RBRACE, // 括号 -> ( ) { }
    EQ, NOT_EQ, // 分支比较 -> == !=
    FUNC, VAR, TRUE, FALSE, IF, ELSE, RETURN // 关键字 -> func var true false if else return
};

struct Token {
    string Literal;
    TokenType type;
};

// 关键字
map<string, TokenType, less<>> keywords = {
        {"func",   TokenType::FUNC},
        {"var",    TokenType::VAR},
        {"true",   TokenType::TRUE},
        {"false",  TokenType::FALSE},
        {"if",     TokenType::IF},
        {"else",   TokenType::ELSE},
        {"return", TokenType::RETURN}
};

TokenType lookup_ident(const string &ident) {
    if (keywords.find(ident) != keywords.end()) {
        return keywords[ident];
    }
    return TokenType::IDENT;
}

#endif //FIREFLY_INTERPRETER_TOKEN_H
