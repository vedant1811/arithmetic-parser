#include "Subtraction.h"

Subtraction::Subtraction(const Expression &left, const Expression &right)
    : BinaryOperator(left, right)
{
}

double Subtraction::evaluate() const
{
    return m_left.evaluate() - m_right.evaluate();
}
