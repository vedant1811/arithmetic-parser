#include "Division.h"

Division::Division(ExpressionPtr const left, ExpressionPtr const right)
    : BinaryOperator(left, right)
{
}

int Division::evaluate() const
{
    return m_left->evaluate() / m_right->evaluate();
}
