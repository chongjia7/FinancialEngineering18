// Comment:
// the base class, Option, is made in this case
// to have the functions & data members common
// to both european & american option
// header file for option.hpp
#ifndef Option_HPP
#define Option_HPP



#include <iostream>
using namespace std;

class Option
{
private:

    void init();	// Initialise all default values
    void Copy(const Option& copy); // copy function

    string optType; // Option name: "C", "P" (put or call, by default) 

    // Gaussian Function 
    double n(double x) const;
    double N(double x) const;

public:

    Option(); // default constructor
    Option(const Option& copy); // copy constructor
    virtual ~Option(); // destructor

    // member operator overloading
    Option& operator = (const Option& copy); // assignment operator

    // pure virtual function common to Options (empty implementation)
    virtual double CallPrice() const = 0;
    virtual double PutPrice() const = 0;
    virtual double Price() const = 0;

    void toggle(); // change option type

};

#endif