/* 定义抽象语法树AST */

#include "../token/token.hpp"
#include <vector>

using namespace std;

class Node {
public:
    virtual string token_literal() = 0;
};

class Statement : public Node {
public:
    virtual string statement_node() = 0;
};

class Expression : public Node {
public:
    virtual string expression_node() = 0;
};

class Identifier {
public:
    Token token;
    string value;
    static string expression_node() {
        return "Identifier";
    }
    string token_literal() const {
        // TODO
    }
};

class Program : public Node {
public:
    vector<Statement *> statements;
    string token_literal() override {
        if (!statements.empty()) {
            return statements[0]->token_literal();
        } else {
            return "";
        }
    }
};

class VarStatement : public Statement {
public:
    Token token;
    Identifier *name{};
    Expression *value{};
    string statement_node() override {
        // TODO
    }
    string token_literal() override {
        // TODO
    }
};

#ifndef FIREFLY_INTERPRETER_AST_HPP
#define FIREFLY_INTERPRETER_AST_HPP

#endif //FIREFLY_INTERPRETER_AST_HPP
