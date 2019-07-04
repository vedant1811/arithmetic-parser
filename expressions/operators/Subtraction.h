#pragma once

#include "BinaryOperator.h"

class Subtraction : public BinaryOperator
{
public:
    Subtraction(ExpressionPtr left, ExpressionPtr right);
    double evaluate() const;
};
