#pragma once

#include "BinaryOperator.h"

class Multiplication : public BinaryOperator
{
public:
    Multiplication(ExpressionPtr left, ExpressionPtr right);
    double evaluate() const;
};
