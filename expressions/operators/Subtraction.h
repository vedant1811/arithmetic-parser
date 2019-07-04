#pragma once

#include "BinaryOperator.h"

class Subtraction : public BinaryOperator
{
public:
    Subtraction(ExpressionPtr const left, ExpressionPtr const right);
    int evaluate() const;
};
