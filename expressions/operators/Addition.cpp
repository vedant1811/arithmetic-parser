#include "Addition.h"

Addition::Addition(ExpressionPtr const left, ExpressionPtr const right)
    : BinaryOperator(left, right)
{
}

int Addition::evaluate() const
{
    return m_left->evaluate() + m_right->evaluate();
}
