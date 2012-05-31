/*
 * identity_argument_makerTest.cpp
 *
 *  Created on: May 28, 2012
 *      Author: simonzehnder
 */
#include <boost/test/unit_test.hpp>
#include <identity_argument_maker.h>

BOOST_AUTO_TEST_SUITE( id_arg_maker )

BOOST_AUTO_TEST_CASE ( getArg ) {
	const int which = 1;
	identity_argument_maker id_arg(which);
	std::vector<std::vector<double> > params;
	for(int i = 0; i < 10; ++i) {
		if(i == which) {
			std::vector<double> temp(5,1.0);
			params.push_back(temp);
		}
		std::vector<double> temp(5);
		params.push_back(temp);
	}
	std::vector<double> ret;
	ret = id_arg.getArgument(params);
	for(size_t i = 0; i < ret.size(); ++i) {
		BOOST_ASSERT( ret[i] == 1.0);
	}

}

BOOST_AUTO_TEST_CASE ( assignOp ) {
	const int which = 1;
	    identity_argument_maker id_arg(2);
		identity_argument_maker id_arg2(which);
		id_arg = id_arg2;
		std::vector<std::vector<double> > params;
		for(int i = 0; i < 10; ++i) {
			if(i == which) {
				std::vector<double> temp(5,1.0);
				params.push_back(temp);
			}
			std::vector<double> temp(5);
			params.push_back(temp);
		}
		std::vector<double> ret;
		ret = id_arg.getArgument(params);
		for(size_t i = 0; i < ret.size(); ++i) {
			BOOST_ASSERT( ret[i] == 1.0);
		}

}
BOOST_AUTO_TEST_SUITE_END()


