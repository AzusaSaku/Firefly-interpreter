/* 定义抽象语法树AST */

#ifndef FIREFLY_INTERPRETER_AST_HPP
#define FIREFLY_INTERPRETER_AST_HPP

#include "token.hpp"
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

// 布尔表达式
class Boolean : public Expression {
public:
    Token token;
    bool value{};
    string token_literal() override {
        return token.Literal;
    }
};

// 语句块
class BlockStatement : public Statement {
public:
    Token token;
    vector<Statement *> statements;
    string statement_node() override {
        // TODO
    }
    string token_literal() override {
        return token.Literal;
    }
};

// IF表达式
class IfExpression : public Expression {
public:
    Token token;
    Expression *condition{};
    BlockStatement *consequence{};
    BlockStatement *alternative{};
    string token_literal() override {
        return token.Literal;
    }
};

// 函数字面量表达式
class FunctionLiteral : public Expression {
public:
    Token token;
    vector<Identifier *> parameters;
    BlockStatement *body{};
    string token_literal() override {
        return token.Literal;
    }
};

// 函数调用表达式
class CallExpression : public Expression {
public:
    Token token;
    Expression *function{};
    vector<Expression *> arguments;
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

#endif //FIREFLY_INTERPRETER_AST_HPP
