#include "Parser.h"
#include <iostream>

using namespace std;

int main(int const argc, char const **argv)
{
    if (argc != 2)
    {
        cerr << "Wrong number of arguments!" << endl;
        cerr << "Usage: $ parse \"<expression>\"" << endl;
        return EXIT_FAILURE;
    }

    try
    {
        int const result = Parser(argv[1]).createAst()->evaluate();
        cout << result << endl;
    }
    catch(invalid_argument const& e)
    {
        cerr << "Invalid Input: " << e.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
