#include "Integer.h"

Integer::Integer(const int value)
    : m_value(value)
{
}

int Integer::evaluate() const 
{
    return m_value;
}
