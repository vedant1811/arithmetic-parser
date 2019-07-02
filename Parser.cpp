#include "Integer.h"
#include "Parser.h"
#include <stack>

Parser::Parser(const char* input)
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

        default:
            if (!std::isdigit(c))
                throw std::invalid_argument("Unknown Literal: " + c);

            auto i = std::make_shared<Integer>(atoi(&c));
            ExpressionPtr e = std::static_pointer_cast<Expression>(i);
            expressionStack.push(e);
            break;
        }
    }
    return ExpressionPtr();
}
