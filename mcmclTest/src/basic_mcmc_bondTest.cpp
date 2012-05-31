/*
 * basic_mcmc_bondTest.cpp
 *
 *  Created on: May 28, 2012
 *      Author: simonzehnder
 */

#include <boost/test/unit_test.hpp>
#include <basic_mcmc_bond.h>
#include <mcmc_parameter.h>
#include <mcmc_likelihood.h>

BOOST_AUTO_TEST_SUITE (basic_mcmc_b)

BOOST_AUTO_TEST_CASE ( Ctors ) {
    std::vector<double> init_par(2,2);
    std::vector<double> steps(2,0.01);
    std::string name = "first";
    mcmc_parameter mcmc_par(init_par, steps, name);
    std::vector<mcmc_parameter> par_vec;
    par_vec.push_back(mcmc_par);
    mcmc_likelihood lik;
    basic_mcmc_bond mcmc_b(lik, par_vec);
    BOOST_ASSERT(mcmc_b.par[0].value[0] == 2);
    BOOST_ASSERT(mcmc_b.par[0].value[1] == 2);
    BOOST_ASSERT(mcmc_b.argms.size() == 0);

    argument_maker am;
    std::vector<argument_maker> am_vec;
    am_vec.push_back(am);
    basic_mcmc_bond mcmc_b2(am_vec, lik, par_vec);
    BOOST_ASSERT(mcmc_b2.par[0].value[0] == 2);
    BOOST_ASSERT(mcmc_b2.par[0].value[1] == 2);
    BOOST_ASSERT(mcmc_b2.argms.size() == 1);
}

BOOST_AUTO_TEST_CASE ( prepareArgs ) {
	std::vector<double> init_par(2,2);
	std::vector<double> steps(2,0.01);
	std::string name = "first";
	mcmc_parameter mcmc_par(init_par, steps, name);
	std::vector<mcmc_parameter> par_vec;
	par_vec.push_back(mcmc_par);
	mcmc_likelihood lik;

	identity_argument_maker am(0);
	std::vector<argument_maker> am_vec;
	am_vec.push_back(am);
	basic_mcmc_bond mcmc_b(am_vec, lik, par_vec);
	mcmc_b.prepareArgs();
}

BOOST_AUTO_TEST_CASE ( subtractOld ) {
	std::vector<double> init_par(2,2);
	std::vector<double> steps(2,0.01);
	std::string name = "first";
	mcmc_parameter mcmc_par(init_par, steps, name);
	std::vector<mcmc_parameter> par_vec;
	par_vec.push_back(mcmc_par);
	mcmc_likelihood lik;

	identity_argument_maker am(0);
	std::vector<argument_maker> am_vec;
	am_vec.push_back(am);
	basic_mcmc_bond mcmc_b(am_vec, lik, par_vec);
	mcmc_b.prepareArgs();
	mcmc_b.subtractOld();
}

BOOST_AUTO_TEST_CASE ( compute ) {
	std::vector<double> init_par(2,2);
	std::vector<double> steps(2,0.01);
	std::string name = "first";
	mcmc_parameter mcmc_par(init_par, steps, name);
	std::vector<mcmc_parameter> par_vec;
	par_vec.push_back(mcmc_par);
	mcmc_likelihood lik;

	identity_argument_maker am(0);
	std::vector<argument_maker> am_vec;
	am_vec.push_back(am);
	basic_mcmc_bond mcmc_b(am_vec, lik, par_vec);
	double result;
	result = mcmc_b.compute(0, 1.6, 0);
	BOOST_ASSERT(result == 0.0);
}

BOOST_AUTO_TEST_CASE ( revise ) {
	std::vector<double> init_par(2,2);
	std::vector<double> steps(2,0.01);
	std::string name = "first";
	mcmc_parameter mcmc_par(init_par, steps, name);
	std::vector<mcmc_parameter> par_vec;
	par_vec.push_back(mcmc_par);
	mcmc_likelihood lik;

	identity_argument_maker am(0);
	std::vector<argument_maker> am_vec;
	am_vec.push_back(am);
	basic_mcmc_bond mcmc_b(am_vec, lik, par_vec);
	double result;
	result = mcmc_b.compute(0, 1.6, 0);
	mcmc_b.revise();
}

BOOST_AUTO_TEST_SUITE_END();



