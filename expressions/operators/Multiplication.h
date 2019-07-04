#pragma once

#include "BinaryOperator.h"

class Multiplication : public BinaryOperator
{
public:
    Multiplication(ExpressionPtr const left, ExpressionPtr const right);
    int evaluate() const;
};
