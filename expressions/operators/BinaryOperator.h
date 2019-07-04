#pragma once 

#include "expressions/Expression.h"

class BinaryOperator : public Expression
{
public:
    BinaryOperator(ExpressionPtr const left, ExpressionPtr const right)
        : m_left(left), m_right(right) {}

    virtual ~BinaryOperator() = default;
protected:
    ExpressionPtr const m_left;
    ExpressionPtr const m_right;
};
