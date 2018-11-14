//
// Created by Chong Jia Yoong  on 2018-09-02.
//

#include "Option.hpp"
#include <iostream>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>
using namespace std;

void Option::init()	// Initialise all default values
{
    optType = "C";
}

void Option::Copy(const Option& copy)
{
    optType = copy.optType;
}

double Option::n(double x) const
{
    boost::math::normal_distribution<double> normalDistribution(0, 1);

    return boost::math::pdf(normalDistribution, x);
}

double Option::N(double x) const
{
    boost::math::normal_distribution<double> normalDistribution(0, 1);

    return boost::math::cdf(normalDistribution, x);
}

Option::Option()
{
    init();
}

Option::Option(const Option& copy1)
{ // Copy constructor
    Copy(copy1);
}

Option::~Option()
{
}

Option& Option::operator = (const Option& copy)
{
    if (this == &copy) return *this;
    Copy(copy);
    return *this;
}

void Option::toggle()
{
    if (optType == "C")
        optType = "P";
    else
        optType = "C";
}












