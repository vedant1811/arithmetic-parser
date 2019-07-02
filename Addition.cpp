#include "Addition.h"

Addition::Addition(const Expression &left, const Expression &right)
    : BinaryOperator(left, right)
{
}

double Addition::evaluate() const
{
    return m_left.evaluate() + m_right.evaluate();
}
