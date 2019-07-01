#include "Expression.h"
#include <string>

class Parser
{
public:
    static Expression& parse(std::string& input);

private:
    // Disallow creating an instance of this object
    Parser() {}
};
