#pragma once 

#include "expressions/Expression.h"

class BinaryOperator : public Expression
{
public:
    BinaryOperator(ExpressionPtr left, ExpressionPtr right)
        : m_left(left), m_right(right) {}

    virtual ~BinaryOperator() = default;
protected:
    ExpressionPtr m_left;
    ExpressionPtr m_right;
};
