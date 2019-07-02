#pragma once

#include "BinaryOperator.h"
#include "Expression.h"

class Parser
{
public:
    Parser(const char* input);
    ExpressionPtr createAst() const;

private:
    const char* m_input;
};
