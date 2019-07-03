#include "Subtraction.h"

Subtraction::Subtraction(ExpressionPtr left, ExpressionPtr right)
    : BinaryOperator(left, right)
{
}

double Subtraction::evaluate() const
{
    return m_left->evaluate() - m_right->evaluate();
}
