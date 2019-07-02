#pragma once

#include "Expression.h"

class Integer : public Expression
{
public:
    Integer(const int value);
    double evaluate() const;

private:
    const int m_value;
};
