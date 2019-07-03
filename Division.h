#pragma once 

#include "BinaryOperator.h"

class Division : public BinaryOperator
{
public:
    Division(ExpressionPtr left, ExpressionPtr right);
    double evaluate() const;
};
