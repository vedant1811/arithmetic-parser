#include "Addition.h"
#include "Division.h"
#include "Multiplication.h"
#include "Integer.h"
#include "Parser.h"
#include "Subtraction.h"
#include <iostream>

Parser::Parser(const char *input)
    : m_input(input)
{
}

ExpressionPtr Parser::createAst() const
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
                               [c](char top) { return top != '('; });
            
            if (operatorStack.empty())
                throw std::invalid_argument("Unbalanced Parathesis");
            operatorStack.pop();
            break;

        default:
            if (isOperator(c))
            {
                moveOperatorsUntil(expressionStack, operatorStack,
                                   [c](char top) { return precendenceOf(top) >= precendenceOf(c); });

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

bool Parser::isOperator(char c)
{
   return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

int Parser::precendenceOf(char c)
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

ExpressionPtr Parser::createOperator(char c, ExpressionPtr left, ExpressionPtr right)
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
                                F condition)
{
    while (!operatorStack.empty() && condition(operatorStack.top()))
    {
        char operatorChar = operatorStack.top();
        operatorStack.pop();

        if (expressionStack.size() < 2)
            throw std::invalid_argument("Missing operands for operator " + operatorChar);
        
        ExpressionPtr right = expressionStack.top();
        expressionStack.pop();
        ExpressionPtr left = expressionStack.top();
        expressionStack.pop();
        expressionStack.push(createOperator(operatorChar, left, right));
    }
}
