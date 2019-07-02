#pragma once

#include "BinaryOperator.h"

class Multiplication : public BinaryOperator
{
public:
    Multiplication(const Expression &left, const Expression &right);
    double evaluate() const;
};
