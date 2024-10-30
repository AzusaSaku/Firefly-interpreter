/* 定义词法分析器 */

#include <string>
#include <utility>

#include "token.hpp"

struct Lexer {
    string input;
    int position{}; // 当前字符
    int read_position{}; // 将要读取的字符
    char ch{}; // 当前字符
};

void read_char(Lexer *l) {
    if (l->read_position >= l->input.length()) {
        l->ch = 0;
    } else {
        l->ch = l->input[l->read_position];
    }
    l->position = l->read_position;
    l->read_position += 1;
}

// 识别字符 -> 字母、下划线
bool isletter(char ch) {
    return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '_';
}

// 识别数字 -> 整型
bool isdigit(char ch) {
    return '0' <= ch && ch <= '9';
}

// 跳过空白字符
void eat_whitespace(Lexer *l) {
    while (l->ch == ' ' || l->ch == '\t' || l->ch == '\n' || l->ch == '\r') {
        read_char(l);
    }
}

string read_identifier(Lexer *l) {
    int position = l->position;
    while (isletter(l->ch)) {
        read_char(l);
    }
    return l->input.substr(position, l->position);
}

string read_number(Lexer *l) {
    int position = l->position;
    while (isdigit(l->ch)) {
        read_char(l);
    }
    return l->input.substr(position, l->position);
}

token next_token(Lexer *l) {
    token tok;

    eat_whitespace(l);

    switch (l->ch) {
        case '=' :
            tok = token{.Literal =  "=", .type =  TK_ASSIGN};
            break;
        case ';' :
            tok = token{.Literal =  ";", .type =  TK_SEMICOLON};
            break;
        case '(' :
            tok = token{.Literal =  "(", .type =  TK_LPAREN};
            break;
        case ')' :
            tok = token{.Literal =  ")", .type =  TK_RPAREN};
            break;
        case ',' :
            tok = token{.Literal =  ",", .type =  TK_COMMA};
            break;
        case '+' :
            tok = token{.Literal =  "+", .type =  TK_PLUS};
            break;
        case '{' :
            tok = token{.Literal =  "{", .type =  TK_LBRACE};
            break;
        case '}' :
            tok = token{.Literal =  "}", .type =  TK_RBRACE};
            break;
        case 0 :
            tok = token{.Literal =  "", .type =  TK_EOF};
            break;
        default:
            if (isletter(l->ch)) {
                tok.Literal = read_identifier(l);
                tok.type = lookup_ident(tok.Literal);
                return tok;
            } else if (isdigit(l->ch)) {
                tok.Literal = read_number(l);
                tok.type = TK_INT;
                return tok;
            }else {
                tok = token{.Literal =  "", .type =  TK_ILLEGAL};
            }
    }
}

Lexer *new_lex(string input) {
    auto *l = new Lexer();
    l->input = std::move(input);
    read_char(l);
    return l;
}

#ifndef FIREFLY_INTERPRETER_LEXER_HPP
#define FIREFLY_INTERPRETER_LEXER_HPP

#endif //FIREFLY_INTERPRETER_LEXER_HPP
