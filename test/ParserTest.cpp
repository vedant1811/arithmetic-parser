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

BOOST_AUTO_TEST_CASE(valid_input)
{
    Parser parser("2 + 3");
    parser.createAst();
}
