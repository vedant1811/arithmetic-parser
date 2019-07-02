#include "Multiplication.h"

Multiplication::Multiplication(const Expression &left, const Expression &right)
    : BinaryOperator(left, right)
{
}

double Multiplication::evaluate() const
{
    return m_left.evaluate() * m_right.evaluate();
}
