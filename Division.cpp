#include "Division.h"

Division::Division(const Expression &left, const Expression &right)
    : BinaryOperator(left, right)
{
}

double Division::evaluate() const
{
    return m_left.evaluate() / m_right.evaluate();
}
