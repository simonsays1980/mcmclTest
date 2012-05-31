/*
 * mcmc_parameterTest.cpp
 *
 *  Created on: May 28, 2012
 *      Author: simonzehnder
 */
#include <boost/test/unit_test.hpp>
#include <mcmc_parameter.h>
#include <vector>
#include <string>

BOOST_AUTO_TEST_SUITE (mcmc_par)

BOOST_AUTO_TEST_CASE ( Ctors ) {
    std::vector<double> init_par(1,1.5);
    std::vector<double> steps(1,0.003);
    std::string name = "mu";
    mcmc_parameter mcmc_par(init_par, steps, name);
    BOOST_ASSERT(mcmc_par.value[0] == 1.5);
    BOOST_ASSERT(mcmc_par.mss[0] == 0.003);

    mcmc_parameter mcmc_par2(mcmc_par);
    BOOST_ASSERT(mcmc_par2.value[0] == 1.5);
    BOOST_ASSERT(mcmc_par2.mss[0] == 0.003);
}

BOOST_AUTO_TEST_SUITE_END()


