#include "Addition.h"

Addition::Addition(ExpressionPtr left, ExpressionPtr right)
    : BinaryOperator(left, right)
{
}

double Addition::evaluate() const
{
    return m_left->evaluate() + m_right->evaluate();
}
