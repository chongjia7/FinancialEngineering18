#ifndef EUROPEANOPTION_GREEKSMATRIXPRICER_HPP
#define EUROPEANOPTION_GREEKSMATRIXPRICER_HPP

#include "EuropeanOption.hpp"
#include <vector>
#include <iostream>

using namespace std;

void GreeksMatrixPricer(const vector<vector<double>>& MatrixParameters1, double b, const string& str)
{

    if (str == "Gamma")
    {
        vector<double> T_vector = MatrixParameters1[0];
        for (int i =0; i!= T_vector.size(); i++)
        {
            EuropeanOption EO_S = EuropeanOption(T_vector[i], 100, 0.36, 0.1, 105);
            cout << "T = " <<  T_vector[i] << ": Gamma of Call Price = " << EO_S.CallGamma(b) << endl;
            EO_S.toggle();
            cout << "    " <<  T_vector[i] << ": Gamma of Put Price = " << EO_S.Gamma(b) << endl;
            EO_S.toggle();
            cout << endl;
        }

        vector<double> K_vector = MatrixParameters1[1];
        for (int i =0; i!= K_vector.size(); i++)
        {
            EuropeanOption EO_S = EuropeanOption(0.5, K_vector[i], 0.36, 0.1, 105);
            cout << "K = " <<  K_vector[i] << ": Gamma of Call Price = " << EO_S.CallGamma(b) << endl;
            EO_S.toggle();
            cout << "    " <<  K_vector[i] << ": Gamma of Put Price = " << EO_S.PutGamma(b) << endl;
            EO_S.toggle();
            cout << endl;
        }

        vector<double> sig_vector = MatrixParameters1[2];
        for (int i =0; i!= sig_vector.size(); i++)
        {
            EuropeanOption EO_S = EuropeanOption(0.5, 100, sig_vector[i], 0.1, 105);
            cout << "sig = " <<  sig_vector[i] << ": Gamma of Call Price = " << EO_S.CallGamma(b) << endl;
            EO_S.toggle();
            cout << "      " <<  sig_vector[i] << ": Gamma of Put Price = " << EO_S.CallGamma(b) << endl;
            EO_S.toggle();
            cout << endl;
        }

        cout << "\n" << endl;
    }

    else if (str == "Delta")
    {

        vector<double> T_vector = MatrixParameters1[0];
        for (int i =0; i!= T_vector.size(); i++)
        {
            EuropeanOption EO_S = EuropeanOption(T_vector[i], 100, 0.36, 0.1, 105);
            cout << "T = " <<  T_vector[i] << ": Delta of Call Price = " << EO_S.CallDelta(b) << endl;
            EO_S.toggle();
            cout << "    " <<  T_vector[i] << ": Delta of Put Price = " << EO_S.PutDelta(b) << endl;
            EO_S.toggle();
            cout << endl;
        }

        vector<double> K_vector = MatrixParameters1[1];
        for (int i =0; i!= K_vector.size(); i++)
        {
            EuropeanOption EO_S = EuropeanOption(0.5, K_vector[i], 0.36, 0.1, 105);
            cout << "K = " <<  K_vector[i] << ": Delta of Call Price = " << EO_S.CallDelta(b) << endl;
            EO_S.toggle();
            cout << "    " <<  K_vector[i] << ": Delta of Put Price = " << EO_S.PutDelta(b) << endl;
            EO_S.toggle();
            cout << endl;
        }

        vector<double> sig_vector = MatrixParameters1[2];
        for (int i =0; i!= sig_vector.size(); i++)
        {
            EuropeanOption EO_S = EuropeanOption(0.5, 100, sig_vector[i], 0.1, 105);
            cout << "sig = " <<  sig_vector[i] << ": Delta of Call Price = " << EO_S.CallDelta(b) << endl;
            EO_S.toggle();
            cout << "      " <<  sig_vector[i] << ": Delta of Put Price = " << EO_S.PutDelta(b) << endl;
            EO_S.toggle();
            cout << endl;
        }

    }

}

#endif //EUROPEANOPTION_GREEKSMATRIXPRICER_HPP

