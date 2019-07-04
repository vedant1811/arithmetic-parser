#include "Multiplication.h"

Multiplication::Multiplication(ExpressionPtr const left, ExpressionPtr const right)
    : BinaryOperator(left, right)
{
}

int Multiplication::evaluate() const
{
    return m_left->evaluate() * m_right->evaluate();
}
