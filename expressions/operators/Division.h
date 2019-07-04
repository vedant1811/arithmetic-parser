#pragma once 

#include "BinaryOperator.h"

class Division : public BinaryOperator
{
public:
    Division(ExpressionPtr const left, ExpressionPtr const right);
    int evaluate() const;
};
