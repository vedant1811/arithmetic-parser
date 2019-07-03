#include "Division.h"

Division::Division(ExpressionPtr left, ExpressionPtr right)
    : BinaryOperator(left, right)
{
}

double Division::evaluate() const
{
    return m_left->evaluate() / m_right->evaluate();
}
