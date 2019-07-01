// Used to form a tree of expressions.
// Evaluating the root will recursively evaluate each child node
class Expression
{
public:
    // Evaluate this expression
    virtual double evaluate() const = 0;
};
