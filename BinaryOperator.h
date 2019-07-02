#pragma once 

#include "Expression.h"

class BinaryOperator : public Expression
{
public:
    BinaryOperator(const Expression& left, const Expression& right)
        : m_left(left), m_right(right) {}

    virtual ~BinaryOperator() = default;
protected:
    const Expression& m_left;
    const Expression& m_right;
};
