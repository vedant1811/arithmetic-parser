#pragma once 

#include "BinaryOperator.h"

class Addition : public BinaryOperator
{
public:
    Addition(const Expression &left, const Expression &right);
    double evaluate() const;
};
