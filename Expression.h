#pragma once

#include <memory>

// Used to form a tree of expressions.
// Evaluating the root will recursively evaluate each child node
class Expression
{
public:
    virtual ~Expression() = default;
    
    // Evaluate this expression
    virtual double evaluate() const = 0;
};

typedef std::shared_ptr<Expression const> ExpressionPtr;
