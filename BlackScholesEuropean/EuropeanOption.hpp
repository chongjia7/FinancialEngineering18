//
// Created by Chong Jia Yoong  on 2018-08-06.
//

// EuropeanOption.hpp
//
// Class that represents  solutions to European options. This is
// an implementation using basic C++ syntax only.
//
// (C) Datasim Component Technology BV 2003-2011
//

#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp


#include <string>
#include "Option.hpp"
using namespace std;

class EuropeanOption : public Option
{
private:

    void init();	// Initialise all default values
    void copy(const EuropeanOption& o2);

    // 'Kernel' functions for option calculation

    // Member data public for convenience; anyway, the format will
    // not change for a plain option.
    double r;		// Interest rate
    double sig;		// Volatility
    double K;		// Strike price
    double T;		// Expiry date
    double b;		// Cost of carry
    double S;       // asset price

    string optType;	// Option name (call, put)
    string unam;	// Name of underlying asset

    // Gaussian functions
    double n(double x) const;
    double N(double x) const;

public:	// Public functions

    // 'Kernel' functions for option calculations
    double CallPrice() const;
    double PutPrice() const;

    double CallDelta(double b) const;
    double PutDelta(double b) const;
    double CallGamma(double b) const;
    double PutGamma(double b) const;

    EuropeanOption();							// Default call option
    EuropeanOption(const EuropeanOption& option2);	// Copy constructor
    EuropeanOption(double T_val, double K_val, double sig_val, double r_val, double S_val); // constructor accepting T,K,sig,r,S
    EuropeanOption(double T_val, double K_val, double sig_val, double r_val, double S_val, double b); // constructor accepting T,K,sig,r,S,b
    EuropeanOption(const string& optionType);	// Create option type
    EuropeanOption(double newS);
    virtual ~EuropeanOption(); // polymorphic destructor

    EuropeanOption& operator = (const EuropeanOption& option2);

    // Functions that calculate option price and sensitivities
    double Price() const;
    double Delta(double b) const;
    double Gamma(double b) const;

    // Modifier functions
    void toggle();		// Change option type (C/P, P/C)
    double PutCallParity(double val, const string& optionType) const;

};

vector<double> MeshArray(double start, double end, double h);



#endif