cmake_minimum_required(VERSION 3.26)
project(Firefly_interpreter)

set(CMAKE_CXX_STANDARD 17)

add_executable(Firefly_interpreter src/main.cpp
        src/token/token.hpp
        src/lexer/lexer.hpp
        src/repl/repl.hpp
        src/ast/ast.hpp
        src/parser/parser.hpp
)
