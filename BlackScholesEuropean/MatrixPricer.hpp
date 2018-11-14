//
// Created by Chong Jia Yoong  on 2018-08-07.
//

#ifndef MATRIXPRICER_HPP
#define MATRIXPRICER_HPP

#include "EuropeanOption.hpp"
#include <vector>
#include <iostream>
using namespace std;

void MatrixPricer(const vector<vector<double>>& MatrixParameters)
{

    vector<double> CPrice1T , PPrice1T;
    vector<double> CPrice2T , PPrice2T;
    vector<double> CPrice3T , PPrice3T;
    vector<double> CPrice4T , PPrice4T;

    vector<double> T_vector = MatrixParameters[0];

    for (int i = 0; i!= T_vector.size(); i++)
    {
        EuropeanOption EO1T = EuropeanOption(T_vector[i], 65, 0.3, 0.08, 60);
        CPrice1T.push_back(EO1T.CallPrice());
        PPrice1T.push_back(EO1T.PutPrice());

        EuropeanOption EO2T = EuropeanOption(T_vector[i], 100, 0.2, 0.00, 100);
        CPrice2T.push_back(EO2T.CallPrice());
        PPrice2T.push_back(EO2T.PutPrice());

        EuropeanOption EO3T = EuropeanOption(T_vector[i], 10, 0.50, 0.12, 5);
        CPrice3T.push_back(EO3T.CallPrice());
        PPrice3T.push_back(EO3T.PutPrice());

        EuropeanOption EO4T =EuropeanOption(T_vector[i],  10, 0.5, 0.12, 100);
        CPrice4T.push_back(EO4T.CallPrice());
        PPrice4T.push_back(EO4T.PutPrice());
    }

    for (int i =0; i!= T_vector.size(); i++)
    {
        cout << "Batch 1: T = " << T_vector[i] << " ,Call Price = " << CPrice1T[i] << ", Put Price = " << PPrice1T[i] << endl;
        cout << "Batch 2: T = " << T_vector[i] << " ,Call Price = " << CPrice2T[i] << ", Put Price = " << PPrice2T[i] << endl;
        cout << "Batch 3: T = " << T_vector[i] << " ,Call Price = " << CPrice3T[i] << ", Put Price = " << PPrice3T[i] << endl;
        cout << "Batch 4: T = " << T_vector[i] << " ,Call Price = " << CPrice4T[i] << ", Put Price = " << PPrice4T[i] << endl;
        cout << endl;
    }

    vector<double> CPrice1sig , PPrice1sig;
    vector<double> CPrice2sig , PPrice2sig;
    vector<double> CPrice3sig , PPrice3sig;
    vector<double> CPrice4sig , PPrice4sig;

    vector<double> sig_vector = MatrixParameters[1];

    for (int i = 0; i!= T_vector.size(); i++)
    {
        EuropeanOption EO1sig = EuropeanOption(0.25, 65, sig_vector[i], 0.08, 60);
        CPrice1sig.push_back(EO1sig.CallPrice());
        PPrice1sig.push_back(EO1sig.PutPrice());

        EuropeanOption EO2sig = EuropeanOption(1.0, 100, sig_vector[i], 0.00, 100);
        CPrice2sig.push_back(EO2sig.CallPrice());
        PPrice2sig.push_back(EO2sig.PutPrice());

        EuropeanOption EO3sig = EuropeanOption(1.0, 10,sig_vector[i], 0.12, 5);
        CPrice3sig.push_back(EO3sig.CallPrice());
        PPrice3sig.push_back(EO3sig.PutPrice());

        EuropeanOption EO4sig =EuropeanOption(30.0,  10, sig_vector[i], 0.12, 100);
        CPrice4sig.push_back(EO4sig.CallPrice());
        PPrice4sig.push_back(EO4sig.PutPrice());
    }

    for (int i =0; i!= sig_vector.size(); i++)
    {
        cout << "Batch 1: sig = " << sig_vector[i] << " ,Call Price = " << CPrice1sig[i] << ", Put Price = " << PPrice1sig[i] << endl;
        cout << "Batch 2: sig = " << sig_vector[i] << " ,Call Price = " << CPrice2sig[i] << ", Put Price = " << PPrice2sig[i] << endl;
        cout << "Batch 3: sig = " << sig_vector[i] << " ,Call Price = " << CPrice3sig[i] << ", Put Price = " << PPrice3sig[i] << endl;
        cout << "Batch 4: sig = " << sig_vector[i] << " ,Call Price = " << CPrice4sig[i] << ", Put Price = " << PPrice4sig[i] << endl;
        cout << endl;
    }


    vector<double> CPrice1K , PPrice1K;
    vector<double> CPrice2K , PPrice2K;
    vector<double> CPrice3K , PPrice3K;
    vector<double> CPrice4K , PPrice4K;

    vector<double> K_vector = MatrixParameters[2];

    for (int i = 0; i!= K_vector.size(); i++)
    {
        EuropeanOption EO1K = EuropeanOption(0.25, K_vector[i], 0.3, 0.08, 60);
        CPrice1K.push_back(EO1K.CallPrice());
        PPrice1K.push_back(EO1K.PutPrice());

        EuropeanOption EO2K = EuropeanOption(1.0, K_vector[i], 0.2, 0.00, 100);
        CPrice2K.push_back(EO2K.CallPrice());
        PPrice2K.push_back(EO2K.PutPrice());

        EuropeanOption EO3K = EuropeanOption(1.0, K_vector[i], 0.50, 0.12, 5);
        CPrice3K.push_back(EO3K.CallPrice());
        PPrice3K.push_back(EO3K.PutPrice());

        EuropeanOption EO4K =EuropeanOption(30.0, K_vector[i], 0.5, 0.12, 100);
        CPrice4K.push_back(EO4K.CallPrice());
        PPrice4K.push_back(EO4K.PutPrice());
    }

    for (int i =0; i!= K_vector.size(); i++)
    {
        cout << "Batch 1: K = " << K_vector[i] << " ,Call Price = " << CPrice1K[i] << ", Put Price = " << PPrice1K[i] << endl;
        cout << "Batch 2: K = " << K_vector[i] << " ,Call Price = " << CPrice2K[i] << ", Put Price = " << PPrice2K[i] << endl;
        cout << "Batch 3: K = " << K_vector[i] << " ,Call Price = " << CPrice3K[i] << ", Put Price = " << PPrice3K[i] << endl;
        cout << "Batch 4: K = " << K_vector[i] << " ,Call Price = " << CPrice4K[i] << ", Put Price = " << PPrice4K[i] << endl;
        cout << endl;
    }

}

#endif //MATRIXPRICER_HPP
