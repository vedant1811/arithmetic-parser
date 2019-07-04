#pragma once 

#include "BinaryOperator.h"

class Division : public BinaryOperator
{
public:
    Division(ExpressionPtr left, ExpressionPtr right);
    int evaluate() const;
};
