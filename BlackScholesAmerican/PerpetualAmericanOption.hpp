//
// Created by Chong Jia Yoong  on 2018-08-06.
//
// header file for PerpetualAmericanOption.hpp derived class

#ifndef PerpetualAmericanOption_hpp
#define PerpetualAmericanOption_hpp

#include "Option.hpp"
#include <string>
using namespace std;

class PerpetualAmericanOption : public Option
{
private:

    void init();	// Initialise all default values
    void copy(const PerpetualAmericanOption& o2);

    // 'Kernel' functions for option calculation

    // Member data public for convenience; anyway, the format will
    // not change for a plain option.
    double r;		// Interest rate
    double sig;		// Volatility
    double K;		// Strike price
    double b;		// Cost of carry
    double S;

    string optType;	// Option name (call, put)
    string unam;	// Name of underlying asset

    // Gaussian functions
    double n(double x) const;
    double N(double x) const;

public:	// Public functions

    // 'Kernel' functions for option calculations
    double CallPrice() const;
    double PutPrice() const;


    PerpetualAmericanOption();							// Default call option
    PerpetualAmericanOption(double K_val, double S_val, double sig_val, double r_val, double b_val);
    PerpetualAmericanOption(const PerpetualAmericanOption& option2);	// Copy constructor
    PerpetualAmericanOption(const string& optionType);	// Create option type
    virtual ~PerpetualAmericanOption();

    PerpetualAmericanOption& operator = (const PerpetualAmericanOption& option2);

    // Functions that calculate option price and sensitivities
    double Price() const;

    // Modifier functions
    void toggle();		// Change option type (C/P, P/C)

};

vector<double> MeshArray(double start, double end, double h);
double PerpetualCall(double K, double S, double sig, double r, double b);
double PerpetualPut (double K, double S, double sig, double r, double b);


#endif