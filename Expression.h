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

// Create a ExpressionPtr by passing in the Class and args for its constructor
// Example: `createExpressionPtr<Addition>(left, right)`
template <typename ExprClass, typename... Args>
    inline static ExpressionPtr
    createExpressionPtr(Args &&... args)
    {
        auto i = std::make_shared<ExprClass>((args)...);
        return std::static_pointer_cast<Expression>(i);
    }
