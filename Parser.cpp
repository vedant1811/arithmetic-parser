#include "expressions/operators/Addition.h"
#include "expressions/operators/Division.h"
#include "expressions/operators/Multiplication.h"
#include "expressions/Integer.h"
#include "Parser.h"
#include "expressions/operators/Subtraction.h"
#include <iostream>

Parser::Parser(const char *input)
    : m_input(input)
{
}

ExpressionPtr const Parser::createAst() const
{
    std::stack<ExpressionPtr> expressionStack;
    std::stack<char> operatorStack;

    for (char& c : std::string(m_input))
    {
        switch (c)
        {
        case ' ':
            // ignore whitespace
            continue;
        
        case '(':
            operatorStack.push(c);
            break;

        case ')':
            moveOperatorsUntil(expressionStack, operatorStack,
                               [c](char const top) { return top != '('; });
            
            if (operatorStack.empty())
                throw std::invalid_argument("Unbalanced Parathesis");
            operatorStack.pop();
            break;

        default:
            if (isOperator(c))
            {
                moveOperatorsUntil(expressionStack, operatorStack,
                                   [c](char const top) { return precendenceOf(top) >= precendenceOf(c); });

                operatorStack.push(c);
            }
            else if (std::isdigit(c))
            {
                expressionStack.push(createExpressionPtr<Integer>(atoi(&c)));
            }
            else
                throw std::invalid_argument("Unknown Literal: " + c);

            break;
        }
    }
    moveOperatorsUntil(expressionStack, operatorStack,
                       [](char) { return true; });
    
    if (expressionStack.size() != 1)
        throw std::invalid_argument("Extra operators and/or operands");
    
    return expressionStack.top();
}

bool Parser::isOperator(char const c)
{
   return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

int Parser::precendenceOf(char const c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 0;
    case '*':
    case '/':
        return 10;
    case '(':
    case ')':
        return -10;

    default:
        throw std::invalid_argument("Not an operator" + c);
    }
}

ExpressionPtr const Parser::createOperator(char const c, ExpressionPtr const left, ExpressionPtr const right)
{
    switch (c)
    {
    case '+':
        return createExpressionPtr<Addition>(left, right);
    case '-':
        return createExpressionPtr<Subtraction>(left, right);
    case '*':
        return createExpressionPtr<Multiplication>(left, right);
    case '/':
        return createExpressionPtr<Division>(left, right);
    default:
        throw std::invalid_argument("Not an operator" + c);
    }
}

template <typename F>
void Parser::moveOperatorsUntil(std::stack<ExpressionPtr>& expressionStack,
                                std::stack<char>& operatorStack,
                                F const condition)
{
    while (!operatorStack.empty() && condition(operatorStack.top()))
    {
        char operatorChar = operatorStack.top();
        operatorStack.pop();

        if (expressionStack.size() < 2)
            throw std::invalid_argument("Missing operands for operator " + operatorChar);
        
        ExpressionPtr const right = expressionStack.top();
        expressionStack.pop();
        ExpressionPtr const left = expressionStack.top();
        expressionStack.pop();
        expressionStack.push(createOperator(operatorChar, left, right));
    }
}
