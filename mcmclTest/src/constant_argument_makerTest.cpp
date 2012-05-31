/*
 * constant_argument_makerTest.cpp
 *
 *  Created on: May 28, 2012
 *      Author: simonzehnder
 */
#include <boost/test/unit_test.hpp>
#include <constant_argument_maker.h>
#include <vector>

BOOST_AUTO_TEST_SUITE ( const_arg_mak )

BOOST_AUTO_TEST_CASE ( Ctors ) {
	const double const_val = 12.0;
	constant_argument_maker const_arg(const_val);
	BOOST_ASSERT( const_arg.CONSTANT_VALUE == 12.0 );

	constant_argument_maker const_arg2(const_arg);
	BOOST_ASSERT( const_arg2.CONSTANT_VALUE == 12.0 );
}

BOOST_AUTO_TEST_CASE ( getArg ) {
    std::vector<std::vector<double> > params;
    for(size_t i = 0; i < 10; ++i) {
    	std::vector<double> temp(5);
    	params.push_back(temp);
    }
    const double const_val = 12.0;
    constant_argument_maker const_arg(const_val);
    std::vector<double> ret_val;
    ret_val = const_arg.getArgument(params);
    for(size_t i = 0; i < ret_val.size(); ++i) {
    	BOOST_ASSERT(ret_val[i] == 12.0);
    }


}
BOOST_AUTO_TEST_SUITE_END()


