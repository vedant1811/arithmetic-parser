#pragma once 

#include "BinaryOperator.h"

class Division : public BinaryOperator
{
public:
    Division(const Expression &left, const Expression &right);
    double evaluate() const;
};
