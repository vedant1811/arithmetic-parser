#define BOOST_TEST_MAIN
#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif

#include "Parser.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(unary_input)
{
    Parser parser("2");
    BOOST_CHECK_EQUAL(parser.createAst()->evaluate(), 2);
}

BOOST_AUTO_TEST_CASE(valid_input)
{
    Parser parser("2 + 3");
    BOOST_CHECK_EQUAL(parser.createAst()->evaluate(), 5);
}

BOOST_AUTO_TEST_CASE(check_precendence)
{
    Parser parser("2 + 3 * 5");
    BOOST_CHECK_EQUAL(parser.createAst()->evaluate(), 17);
}

BOOST_AUTO_TEST_CASE(paranthesis)
{
    Parser parser("(2 + 3) * 5");
    BOOST_CHECK_EQUAL(parser.createAst()->evaluate(), 25);
}

BOOST_AUTO_TEST_CASE(parantheses)
{
    Parser parser("(2 + 3) * 5");
    BOOST_CHECK_EQUAL(parser.createAst()->evaluate(), 25);
}

BOOST_AUTO_TEST_CASE(nested_parantheses)
{
    Parser parser("(2 * (3 + 2)) * 5");
    BOOST_CHECK_EQUAL(parser.createAst()->evaluate(), 50);
}

BOOST_AUTO_TEST_CASE(complex_parantheses)
{
    Parser parser("(2 * (3 + 2)) * 5 + 5 / (3 - 1)");
    BOOST_CHECK_EQUAL((int)parser.createAst()->evaluate(), 52);
}

BOOST_AUTO_TEST_CASE(division)
{
    Parser parser("6/2");
    BOOST_CHECK_EQUAL(parser.createAst()->evaluate(), 3);
}

BOOST_AUTO_TEST_CASE(integer_division)
{
    Parser parser("1/2");
    BOOST_CHECK_EQUAL((int)parser.createAst()->evaluate(), 0);
}

BOOST_AUTO_TEST_CASE(integer_division_2)
{
    Parser parser("3*1/6*2");
    BOOST_CHECK_EQUAL((int)parser.createAst()->evaluate(), 1);
}

BOOST_AUTO_TEST_CASE(integer_division_rounding)
{
    Parser parser("1/2+1/2");
    BOOST_CHECK_EQUAL((int)parser.createAst()->evaluate(), 0);
}

BOOST_AUTO_TEST_CASE(integer_division_rounding_2)
{
    Parser parser("2/6*3");
    BOOST_CHECK_EQUAL((int)parser.createAst()->evaluate(), 1);
}

BOOST_AUTO_TEST_CASE(arithmetic)
{
    Parser parser("(4 + 5 * (7 - 3)) - 2");
    BOOST_CHECK_EQUAL((int)parser.createAst()->evaluate(), 22);
}

BOOST_AUTO_TEST_CASE(arithmetic_2)
{
    Parser parser("4+5+7/2");
    BOOST_CHECK_EQUAL((int)parser.createAst()->evaluate(), 12);
}
