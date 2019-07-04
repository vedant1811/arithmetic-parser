#pragma once

#include "BinaryOperator.h"

class Subtraction : public BinaryOperator
{
public:
    Subtraction(ExpressionPtr left, ExpressionPtr right);
    int evaluate() const;
};
