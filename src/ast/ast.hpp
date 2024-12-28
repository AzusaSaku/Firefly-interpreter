/* 定义抽象语法树AST */

#include "../token/token.hpp"
#include <vector>

using namespace std;

class Node {
public:
    virtual string token_literal() = 0;
//    virtual void print() = 0;
};

class Statement : public Node { // 语句
public:
    virtual string statement_node() = 0;
};

class Expression : public Node { // 表达式
public:
    string token_literal() override{
        return "";
    };
    virtual string expression_node(){
        return "";
    };
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

//    void print() override {
//        for (auto &stmt : statements) {
//            stmt->print();
//        }
//    }
};

// 标识符表达式
class Identifier : public Expression {
public:
    Token token;
    string value;
    string token_literal() override {
        return token.Literal;
    }
};

// 整型字面量表达式
class IntegerLiteral : public Expression {
public:
    Token token;
    int value{};
    string token_literal() override {
        return token.Literal;
    }
};

// 前缀表达式
class PrefixExpression : public Expression {
public:
    Token token;
    string op;
    Expression *right{};
    string token_literal() override {
        return token.Literal;
    }
};

// 中缀表达式
class InfixExpression : public Expression {
public:
    Token token;
    Expression *left{};
    string op;
    Expression *right{};
    string token_literal() override {
        return token.Literal;
    }
};

// VAR语句
class VarStatement : public Statement {
public:
    Token token;
    Identifier *name{};
    Expression *value{};
    string statement_node() override {
        // TODO
    }
    string token_literal() override {
        return token.Literal;
    }
};

// RETURN语句
class ReturnStatement : public Statement {
public:
    Token token;
    Expression *return_value{};
    string statement_node() override {
        // TODO
    }
    string token_literal() override {
        return token.Literal;
    }
};

// 仅由一个表达式构成的语句
class ExpressionStatement : public Statement {
public:
    Token token;
    Expression *expression{};
    string statement_node() override {
        // TODO
    }
    string token_literal() override {
        return token.Literal;
    }
};

#ifndef FIREFLY_INTERPRETER_AST_HPP
#define FIREFLY_INTERPRETER_AST_HPP

#endif //FIREFLY_INTERPRETER_AST_HPP
