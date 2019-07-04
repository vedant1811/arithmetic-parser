#define BOOST_TEST_MAIN
#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif

#include "Parser.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(invalid_input)
{
    Parser parser("test");
    BOOST_CHECK_THROW(parser.createAst(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(imbalanced_paratheses)
{
    Parser parser("(2 + 3))");
    BOOST_CHECK_THROW(parser.createAst(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(imbalanced_paratheses_2)
{
    Parser parser("(2 + 3");
    BOOST_CHECK_THROW(parser.createAst(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(large_input)
{
    Parser parser("10 + 1");
    BOOST_CHECK_THROW(parser.createAst(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(missing_operand)
{
    Parser parser("-1");
    BOOST_CHECK_THROW(parser.createAst(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(missing_operand_2)
{
    Parser parser("+1");
    BOOST_CHECK_THROW(parser.createAst(), std::invalid_argument);
}
