#include "Multiplication.h"

Multiplication::Multiplication(ExpressionPtr left, ExpressionPtr right)
    : BinaryOperator(left, right)
{
}

int Multiplication::evaluate() const
{
    return m_left->evaluate() * m_right->evaluate();
}
