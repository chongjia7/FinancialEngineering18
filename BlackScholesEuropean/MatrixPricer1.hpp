//
// Created by Chong Jia Yoong  on 2018-08-07.
//

#ifndef MATRIXPRICER_HPP
#define MATRIXPRICER_HPP

#include "EuropeanOption.hpp"
#include <vector>
#include <iostream>

vector<double> T_vector = MeshArray(25, 75, 1);
vector<double> K_vector = MeshArray(50, 100, 1);
vector<double> sig_vector = MeshArray(0, 50, 1);

vector<vector<double>> MatrixPricer(vector<vector<double>> MatrixParameters ,string optType);

vector<vector<double>> MatrixPricer(vector<vector<double>> MatrixParameters ,string optType)
    {
        vector<vector<double>> MatrixOfPrices;
        vector<double> Matrix_T, Matrix_K, Matrix_sig;

        if (optType == "C")
        {
            for (int i = 0; i != T_vector.size() + 1; i++) {
                Matrix_T.push_back(EuropeanOption(T_vector[i], 65, 0.3, 0.08, 60).CallPrice());
                cout << "T :" << T_vector[i] << "Batch 1 Call Price :" << EuropeanOption(T_vector[i], 65, 0.3, 0.08, 60).CallPrice();

                Matrix_T.push_back(EuropeanOption(T_vector[i], 100, 0.2, 0.00, 100).CallPrice());
                cout << "T :" << T_vector[i] << "Batch 2 Call Price :" << EuropeanOption(T_vector[i], 100, 0.2, 0.00, 100).CallPrice();

                Matrix_T.push_back(EuropeanOption(T_vector[i], 10, 0.5, 0.12, 5).CallPrice());
                cout << "T :" << T_vector[i] << "Batch 3 Call Price :" << EuropeanOption(T_vector[i], 10, 0.5, 0.12, 5).CallPrice();

                Matrix_T.push_back(EuropeanOption(T_vector[i], 100, 0.3, 0.08, 100.0).CallPrice());
                cout << "T :" << T_vector[i] << "Batch 4 Call Price :" << EuropeanOption(T_vector[i], 100, 0.3, 0.08, 100.0).CallPrice();

                MatrixOfPrices.push_back(Matrix_T);

                Matrix_K.push_back(EuropeanOption(0.25, K_vector[i], 0.3, 0.08, 60).CallPrice());
                cout << "T :" << T_vector[i] << "Batch 1 Call Price :" << EuropeanOption(0.25, K_vector[i], 0.3, 0.08, 60).CallPrice();

                     Matrix_K.push_back(EuropeanOption(1.0, K_vector[i], 0.2, 0.00, 100).CallPrice());
                cout << "T :" << T_vector[i] << "Batch 1 Call Price :" << EuropeanOption(1.0, K_vector[i], 0.2, 0.00, 100).CallPrice();

                Matrix_K.push_back(EuropeanOption(1.0, K_vector[i], 0.5, 0.12, 5).CallPrice());
                cout << "T :" << T_vector[i] << "Batch 1 Call Price :" << EuropeanOption(1.0, K_vector[i], 0.5, 0.12, 5).CallPrice();

                Matrix_K.push_back(EuropeanOption(30.0, K_vector[i], 0.3, 0.08, 100.0).CallPrice());
                cout << "T :" << T_vector[i] << "Batch 1 Call Price :" << EuropeanOption(30.0, K_vector[i], 0.3, 0.08, 100.0).CallPrice();

                MatrixOfPrices.push_back(Matrix_K);

                Matrix_sig.push_back(EuropeanOption(0.25, 65, sig_vector[i], 0.08, 60).CallPrice());
                Matrix_sig.push_back(EuropeanOption(1.0, 100, sig_vector[i], 0.00, 100).CallPrice());
                Matrix_sig.push_back(EuropeanOption(1.0, 10, sig_vector[i], 0.12, 5).CallPrice());
                Matrix_sig.push_back(EuropeanOption(30.0, 100, sig_vector[i], 0.08, 100.0).CallPrice());

                MatrixOfPrices.push_back(Matrix_sig);
            }


        }

        else {

            for (int i = 0; i != T_vector.size() + 1; i++)
            {
                Matrix_T.push_back(EuropeanOption(T_vector[i], 65, 0.3, 0.08, 60).PutPrice());
                Matrix_T.push_back(EuropeanOption(T_vector[i], 100, 0.2, 0.00, 100).PutPrice());
                Matrix_T.push_back(EuropeanOption(T_vector[i], 10, 0.5, 0.12, 5).PutPrice());
                Matrix_T.push_back(EuropeanOption(T_vector[i], 100, 0.3, 0.08, 100.0).PutPrice());

                MatrixOfPrices.push_back(Matrix_T);

                Matrix_K.push_back(EuropeanOption(0.25, K_vector[i], 0.3, 0.08, 60).PutPrice());
                Matrix_K.push_back(EuropeanOption(1.0, K_vector[i], 0.2, 0.00, 100).PutPrice());
                Matrix_K.push_back(EuropeanOption(1.0, K_vector[i], 0.5, 0.12, 5).PutPrice());
                Matrix_K.push_back(EuropeanOption(30.0, K_vector[i], 0.3, 0.08, 100.0).PutPrice());

                MatrixOfPrices.push_back(Matrix_K);

                Matrix_sig.push_back(EuropeanOption(0.25, 65, sig_vector[i], 0.08, 60).PutPrice());
                Matrix_sig.push_back(EuropeanOption(1.0, 100, sig_vector[i], 0.00, 100).PutPrice());
                Matrix_sig.push_back(EuropeanOption(1.0, 10, sig_vector[i], 0.12, 5).PutPrice());
                Matrix_sig.push_back(EuropeanOption(30.0, 100, sig_vector[i], 0.08, 100.0).PutPrice());

                MatrixOfPrices.push_back(Matrix_sig);
            }

        }

        return MatrixOfPrices;
    }

#endif //MATRIXPRICER_HPP

/*
for (int i = 0; i != T_vector.size(); i++)
{
//Matrix_T.push_back(EuropeanOption(T_vector[i], 65, 0.3, 0.08, 60).CallPrice());
cout << "T = " << T_vector[i] << ": Batch 1 Call Price :"
<< EuropeanOption(T_vector[i], 65, 0.3, 0.08, 60).CallPrice() <<
", Put Price :" << EuropeanOption(T_vector[i], 65, 0.3, 0.08, 60).PutPrice() << endl;

//Matrix_T.push_back(EuropeanOption(T_vector[i], 100, 0.2, 0.00, 100).CallPrice());
cout << "T = " << T_vector[i] << ": Batch 2 Call Price :"
<< EuropeanOption(T_vector[i], 100, 0.2, 0.00, 100).CallPrice() <<
", Put Price :" << EuropeanOption(T_vector[i], 100, 0.2, 0.00, 100).PutPrice() << endl;

//Matrix_T.push_back(EuropeanOption(T_vector[i], 10, 0.5, 0.12, 5).CallPrice());
cout << "T = " << T_vector[i] << ": Batch 3 Call Price :"
<< EuropeanOption(T_vector[i], 10, 0.5, 0.12, 5).CallPrice() <<
", Put Price :" << EuropeanOption(T_vector[i], 10, 0.5, 0.12, 5).PutPrice() << endl;

// Matrix_T.push_back(EuropeanOption(T_vector[i], 100, 0.3, 0.08, 100.0).CallPrice());
cout << "T = " << T_vector[i] << ": Batch 4 Call Price :"
<< EuropeanOption(T_vector[i], 100, 0.3, 0.08, 100.0).CallPrice() <<
", Put Price :" << EuropeanOption(T_vector[i], 100, 0.3, 0.08, 100.0).PutPrice() << "\n" << endl;
}

for (int i = 0; i != K_vector.size(); i++)
{
//Matrix_T.push_back(EuropeanOption(T_vector[i], 65, 0.3, 0.08, 60).CallPrice());
cout << "K = " << K_vector[i] << ": Batch 1 Call Price :"
<< EuropeanOption(K_vector[i], 65, 0.3, 0.08, 60).CallPrice() <<
", Put Price :" << EuropeanOption(K_vector[i], 65, 0.3, 0.08, 60).PutPrice() << endl;

//Matrix_T.push_back(EuropeanOption(T_vector[i], 100, 0.2, 0.00, 100).CallPrice());
cout << "K = " << K_vector[i] << ": Batch 2 Call Price :"
<< EuropeanOption(K_vector[i], 100, 0.2, 0.00, 100).CallPrice() <<
", Put Price :" << EuropeanOption(K_vector[i], 100, 0.2, 0.00, 100).PutPrice() << endl;

//Matrix_T.push_back(EuropeanOption(T_vector[i], 10, 0.5, 0.12, 5).CallPrice());
cout << "K = " << K_vector[i] << ": Batch 3 Call Price :"
<< EuropeanOption(K_vector[i], 10, 0.5, 0.12, 5).CallPrice() <<
", Put Price :" << EuropeanOption(K_vector[i], 10, 0.5, 0.12, 5).PutPrice() << endl;

// Matrix_T.push_back(EuropeanOption(T_vector[i], 100, 0.3, 0.08, 100.0).CallPrice());
cout << "K = " << K_vector[i] << ": Batch 4 Call Price :"
<< EuropeanOption(K_vector[i], 100, 0.3, 0.08, 100.0).CallPrice() <<
", Put Price :" << EuropeanOption(K_vector[i], 100, 0.3, 0.08, 100.0).PutPrice() << "\n" << endl;
}


for (int i = 0; i != sig_vector.size(); i++)
{
//Matrix_T.push_back(EuropeanOption(T_vector[i], 65, 0.3, 0.08, 60).CallPrice());
cout << "sig = " << sig_vector[i] << ": Batch 1 Call Price :" << EuropeanOption(sig_vector[i], 65, 0.3, 0.08, 60).CallPrice() <<
", Put Price :" << EuropeanOption(sig_vector[i], 65, 0.3, 0.08, 60).PutPrice() << endl;

//Matrix_T.push_back(EuropeanOption(T_vector[i], 100, 0.2, 0.00, 100).CallPrice());
cout << "sig = " << sig_vector[i] << ": Batch 2 Call Price :" << EuropeanOption(sig_vector[i], 100, 0.2, 0.00, 100).CallPrice() <<
", Put Price :" << EuropeanOption(sig_vector[i], 100, 0.2, 0.00, 100).PutPrice() << endl;

//Matrix_T.push_back(EuropeanOption(T_vector[i], 10, 0.5, 0.12, 5).CallPrice());
cout << "sig = " << sig_vector[i] << ": Batch 3 Call Price :" << EuropeanOption(sig_vector[i], 10, 0.5, 0.12, 5).CallPrice() <<
", Put Price :" << EuropeanOption(sig_vector[i], 10, 0.5, 0.12, 5).PutPrice() << endl;

// Matrix_T.push_back(EuropeanOption(T_vector[i], 100, 0.3, 0.08, 100.0).CallPrice());
cout << "sig = " << sig_vector[i] << ": Batch 4 Call Price :" << EuropeanOption(sig_vector[i], 100, 0.3, 0.08, 100.0).CallPrice() <<
", Put Price :" << EuropeanOption(sig_vector[i], 100, 0.3, 0.08, 100.0).PutPrice() <<"\n"<< endl;

}
*/