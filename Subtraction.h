#pragma once

#include "BinaryOperator.h"

class Subtraction : public BinaryOperator
{
public:
    Subtraction(const Expression &left, const Expression &right);
    double evaluate() const;
};
