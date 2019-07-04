#pragma once 

#include "BinaryOperator.h"

class Addition : public BinaryOperator
{
public:
    Addition(ExpressionPtr const left, ExpressionPtr const right);
    int evaluate() const;
};
