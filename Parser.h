#pragma once

#include "BinaryOperator.h"
#include "Expression.h"
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
    ExpressionPtr createAst() const;

private:
    static bool isOperator(char c);
    static int precendenceOf(char c);

    static ExpressionPtr createOperator(char c, ExpressionPtr left, ExpressionPtr right);
    
    /**
     * Moves operators from @param operatorStack to @param expressionStack,
     * while there are items in stack and condition is true
     */
    template<typename F>
    static void moveOperatorsUntil(std::stack<ExpressionPtr>& expressionStack,
                                   std::stack<char>& operatorStack,
                                   F condition);

    const char* m_input;
};
