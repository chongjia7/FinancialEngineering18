// EurpeanOption.cpp
//
//	Author: Daniel Duffy
//
// (C) Datasim Component Technology BV 2003-2011
//


#include "EuropeanOption.hpp"
#include <cmath>
#include <iostream>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>

using namespace boost::math;

EuropeanOption::EuropeanOption(double T_val, double K_val, double sig_val, double r_val, double S_val)
{
    T = T_val; K = K_val; sig = sig_val; r = r_val; S = S_val; b = r_val;
}

EuropeanOption::EuropeanOption(double T_val, double K_val, double sig_val, double r_val, double S_val, double b_val)
{
    T = T_val; K = K_val; sig = sig_val; r = r_val; S = S_val; b = b_val;
}

// In general, we would use similar functions in Boost::Math Toolkit

double EuropeanOption::n(double x) const
{

    boost::math::normal_distribution<double> normalDistribution(0, 1);
    return boost::math::pdf(normalDistribution, x);


}

double EuropeanOption::N(double x) const
{ // The approximation to the cumulative normal distribution

    boost::math::normal_distribution<double> normalDistribution(0, 1);
    return boost::math::cdf(normalDistribution, x);

}


// Kernel Functions (Haug)
double EuropeanOption::CallPrice() const
{

    double tmp = sig * sqrt(T);
    double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
    double d2 = d1 - tmp;
    normal_distribution<> normalDist(0, 1);

    return (S * exp((b - r) * T) * cdf(normalDist, d1)) - (K * exp(-r * T) * cdf(normalDist, d2));

}

double EuropeanOption::PutPrice() const
{

    double tmp = sig * sqrt(T);
    double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
    double d2 = d1 - tmp;
    normal_distribution<> normalDist(0, 1);

    return (K * exp(-r * T) * cdf(normalDist, -d2)) - (S * exp((b - r) * T) * cdf(normalDist, -d1));

}

double EuropeanOption::CallDelta(double b) const
{
    normal_distribution<> normalDist(0, 1);
    double tmp = sig * sqrt(T);
    double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
    return exp((b - r) * T) * cdf(normalDist, d1);
}

double EuropeanOption::PutDelta(double b) const
{
    return CallDelta(b) - exp((b - r) * T);
}

double EuropeanOption::CallGamma(double b) const
{
    normal_distribution<> normalDist(0, 1);
    double tmp = sig * sqrt(T);
    double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / tmp;
    return pdf(normalDist, d1) * exp((b - r) * T) / (S * sig * sqrt(T));
}

double EuropeanOption::PutGamma(double b) const
{
    return CallGamma(b);
}


void EuropeanOption::init()
{	// Initialise all default values

    // Default values
    r = 0.05;
    sig= 0.2;

    K = 110.0;
    T = 0.5;

    b = r;			// Black and Scholes stock option model (1973)

    optType = "C";		// European Call Option (this is the default type)
}

void EuropeanOption::copy( const EuropeanOption& o2)
{

    r	= o2.r;
    sig = o2.sig;
    K	= o2.K;
    T	= o2.T;
    b	= o2.b;

    optType = o2.optType;

}

EuropeanOption::EuropeanOption()
{ // Default call option

    init();
}


EuropeanOption::EuropeanOption(const EuropeanOption& o2)
{ // Copy constructor

    copy(o2);
}

EuropeanOption::EuropeanOption(double newS)
{ // constructor accepting S
    S = newS;
}

EuropeanOption::EuropeanOption (const string& optionType)
{	// Create option type

    init();
    optType = optionType;

    if (optType == "c")
        optType = "C";

}


EuropeanOption::~EuropeanOption()
{

}


EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option2)
{

    if (this == &option2) return *this;

    copy (option2);

    return *this;
}

double EuropeanOption::Price() const
{


    if (optType == "C")
    {
        cout << "calling call\n";
        return CallPrice();
    }
    else
    {
        cout << "calling put\n";
        return PutPrice();
    }
}

double EuropeanOption::Delta(double b) const
{
    if (optType == "C")
        return CallDelta(b);
    else
        return PutDelta(b);

}


double EuropeanOption::Gamma(double b) const
{
    if (optType == "C")
        return CallGamma(b);
    else
        return PutGamma(b);
}

// Modifier functions
void EuropeanOption::toggle()
{ // Change option type (C/P, P/C)

    if (optType == "C")
        optType = "P";
    else
        optType = "C";
}

double EuropeanOption::PutCallParity(double val, const string& optType) const
{
    if (optType == "P")
    {
        return val - S + K * exp(-r*T);
    }

    else
    {
        return val + S - K * exp(-r*T);
    }

}

vector<double> MeshArray(double start, double end, double h)
{
    vector<double> Mesh;
    for (int i = start; i != end + 1; i = i + h)
    {
        Mesh.push_back(i);
    }
    return Mesh;
}







