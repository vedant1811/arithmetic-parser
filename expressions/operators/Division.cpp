#include "Division.h"

Division::Division(ExpressionPtr left, ExpressionPtr right)
    : BinaryOperator(left, right)
{
}

int Division::evaluate() const
{
    return m_left->evaluate() / m_right->evaluate();
}
