#pragma once 

#include "BinaryOperator.h"

class Addition : public BinaryOperator
{
public:
    Addition(ExpressionPtr left, ExpressionPtr right);
    double evaluate() const;
};
