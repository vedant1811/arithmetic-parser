#include "Subtraction.h"

Subtraction::Subtraction(ExpressionPtr left, ExpressionPtr right)
    : BinaryOperator(left, right)
{
}

int Subtraction::evaluate() const
{
    return m_left->evaluate() - m_right->evaluate();
}
