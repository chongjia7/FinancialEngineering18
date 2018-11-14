//
// Created by Chong Jia Yoong  on 2018-08-06.
//
#include "EuropeanOption.cpp"
#include "EuropeanOption.hpp"
// pass by reference and using struct so

class BatchParameters
{
	private:
		double T;
		double K;
		double sig;
		double r;
		double S;

	public:
		BatchParameters();
		//BatchParameters(const EuropeanOption& copy); // no need copy constructor
		BatchParameters(double T, double K, double sig, double r, double S);

}

BatchParameters::BatchParameters()
{
	double T = 0.25; double K = 65; double sig = 0.30;double r = 0.08;double S = 60;
}
/*
BatchParameters::BatchParameters(const BatchParameters& copy)
{
	T = copy.T; K = copy.K; sig = copy.sig; r = copy.r; S = copy.S;
}
 */

BatchParameters::BatchParameters(double T_val, double K_val, double sig_val, double r_val, double S_val) : T(T_val), K(K_val), sig(sig_val), r(r_val), S(S_val)
{
}

double BatchParameters::CallPrice()
{
	return EuropeanOption::CallPrice(S);

}

double BatchParameters::PutPrice()
{
	return EuropeanOption::PutPrice(S);

}

BatchParameters::~BatchParameters()
{
}


