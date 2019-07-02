#include "Integer.h"

Integer::Integer(const int value)
    : m_value(value)
{
}

double Integer::evaluate() const 
{
    return m_value;
}
