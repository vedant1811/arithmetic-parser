#pragma once

#include "expressions/operators/BinaryOperator.h"
#include "expressions/Expression.h"
#include <stack>

class Parser
{
public:
    Parser(const char* input);

    /**
     * Create the Abstract Syntax Tree for the given input.
     * Implements a simplified version of the Shunting-Yard algorithm.
     * 
     * @returns the root of the AST
     */
    ExpressionPtr const createAst() const;

private:
    static bool isOperator(char const c);
    static int precendenceOf(char const c);

    static ExpressionPtr const createOperator(char const c, ExpressionPtr const left, ExpressionPtr const right);
    
    /**
     * Moves operators from @param operatorStack to @param expressionStack,
     * while there are items in stack and condition is true
     */
    template<typename F>
    static void moveOperatorsUntil(std::stack<ExpressionPtr>& expressionStack,
                                   std::stack<char>& operatorStack,
                                   F const condition);

    const char* m_input;
};
