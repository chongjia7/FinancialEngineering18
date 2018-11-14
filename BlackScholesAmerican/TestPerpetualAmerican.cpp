// PerpetualAmerican.hpp
//
// Perpetual American option, Haug 2007 page 109-110.
// test program for Group B
#include <cmath>
#include <iostream>
#include "PerpetualAmericanOption.hpp"
#include <vector>
#include "MatrixPricer.hpp"
using namespace std;

// !! The variable b is cost of carry (b = r -q for a dividend-paying stock)


int main()
{
	cout.precision(5);
	double K  = 100;
	double S = 110;
	double sig = 0.1;
	double r = 0.1;
	double b = 0.02;

	cout << "Part b)" << endl;
	cout << "Put Price" << "S:  " << PerpetualPut (K, S, sig, r, b) << endl;
	cout << "Call Price" << "S: " << PerpetualCall (K, S, sig, r, b) << endl;
	cout << endl;

	cout << "Part c)" << endl;
	vector<double> S_vector = MeshArray(10, 50, 1);

	for (int i = 0; i!= S_vector.size();i++)
	{
		cout << "S = " << S_vector[i] << " : Call Price = "  << PerpetualCall(K, S_vector[i], sig, r, b) << ", Put Price = " << PerpetualPut(K, S_vector[i], sig, r, b) << endl;
	}


	cout << "\nPart d)" << endl;
	//vector<double> T_vector = MeshArray(1, 50, 1);
	vector<double> sig_vector = MeshArray(1, 50, 1);
	vector<double> K_vector = MeshArray(51, 100, 1);

	vector<vector<double>> MatrixParameters;
	//MatrixParameters.push_back(T_vector);
	MatrixParameters.push_back(sig_vector);
	MatrixParameters.push_back(K_vector);

	cout << endl;

	MatrixPricer(MatrixParameters);

	/*
	// Examples fom Haug 2007
	K = 100.0; r = 0.1; b = 0.02;

	S = 90.0;
	cout << "\nPrice, put, " << ", S:  " << PerpetualPut (K, S, sig, r, b) << endl;
	cout << "Price, call, " << ", S: " << PerpetualCall (K, S, sig, r, b) << endl;

	S = 120.0;
	cout << "\nPrice, put, " << ", S:  " << PerpetualPut (K, S, sig, r, b) << endl;
	cout << "Price, call, " << ", S: " << PerpetualCall (K, S, sig, r, b) << endl;

	S = 130.0;
	cout << "\nPrice, put, " << ", S:  " << PerpetualPut (K, S, sig, r, b) << endl;
	cout << "Price, call, " << ", S: " << PerpetualCall (K, S, sig, r, b) << endl;
	*/
	return 0;
}
