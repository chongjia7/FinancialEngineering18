#include <iostream>
#include <vector>
#include "EuropeanOption.hpp"
#include "MatrixPricer.hpp"
#include "GreeksMatrixPricer.hpp"
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <cmath>


using namespace std;

int main()
{

    vector<double> CallPriceVecA, PutPriceVecA;

    EuropeanOption EO1 = EuropeanOption(0.25, 65, 0.3, 0.08, 60);
    EuropeanOption EO2 = EuropeanOption(1.0, 100, 0.2, 0.00, 100);
    EuropeanOption EO3 = EuropeanOption(1.0,  10, 0.5, 0.12, 5);
    EuropeanOption EO4 = EuropeanOption(30.0, 100, 0.3, 0.08, 100);

    cout << "Exact Solutions of One-Factor Plain Option:" << endl;
    cout << endl;
    cout << "Part a) " << endl;
    // A
    cout << "Batch 1: " << endl;
    cout << "Call Price = " << EO1.CallPrice() << " ,Put Price = " << EO1.PutPrice() << "\n" << endl ;

    cout << "Batch 2: " << endl;
    cout << "Call Price = " << EO2.CallPrice() << " ,Put Price = " << EO2.PutPrice() << "\n" << endl ;

    cout << "Batch 3: " << endl;
    cout << "Call Price = " << EO3.CallPrice() << ", Put Price = " << EO3.PutPrice() << "\n" << endl ;

    cout << "Batch 4: " << endl;
    cout << "Cal Price = " << EO4.CallPrice() << ", Put Price = " << EO4.PutPrice() << "\n" << endl ;

    // B
    cout << "Part b) " << endl;
    cout << "Batch 1: " << endl;
    cout << "Call Price = " << EO1.PutCallParity(EO1.PutPrice(), "C" ) <<
         ",Put Price = " <<  EO1.PutCallParity(EO1.CallPrice(), "P") << "\n" << endl;

    cout << "Batch 2: " << endl;
    cout << "Call Price = " << EO2.PutCallParity(EO2.PutPrice(), "C" ) <<
        ",Put Price = " << EO2.PutCallParity(EO2.CallPrice(), "P") << "\n" << endl;

    cout << "Batch 3: " << endl;
    cout << "Call Price = " << EO3.PutCallParity(EO3.PutPrice(), "C" ) <<
         ",Put Price = " << EO3.PutCallParity(EO3.CallPrice(), "P") << "\n" << endl;

    cout << "Batch 4: " << endl;
    cout << "Call Price = " << EO4.PutCallParity(EO4.PutPrice(), "C" ) <<
         ",Put Price = " << EO4.PutCallParity(EO4.CallPrice(), "P") << "\n" << endl;

    cout << "Part c)" << endl;
    vector<double> S_vector = MeshArray(10, 50, 1);
    vector<double> CPrice1 , PPrice1;
    vector<double> CPrice2 , PPrice2;
    vector<double> CPrice3 , PPrice3;
    vector<double> CPrice4 , PPrice4;

    for (int i = 0; i!= S_vector.size(); i++)
    {
        EuropeanOption EO1c = EuropeanOption(0.25, 65, 0.3, 0.08, S_vector[i]);
        CPrice1.push_back(EO1c.CallPrice());
        PPrice1.push_back(EO1c.PutPrice());
        EuropeanOption EO2c = EuropeanOption(1.0, 100, 0.2, 0.00, S_vector[i]);
        CPrice2.push_back(EO2c.CallPrice());
        PPrice2.push_back(EO2c.PutPrice());

        EuropeanOption EO3c = EuropeanOption(1.0, 10, 0.50, 0.12, S_vector[i]);
        CPrice3.push_back(EO3c.CallPrice());
        PPrice3.push_back(EO3c.PutPrice());

        EuropeanOption EO4c =EuropeanOption(1.0,  10, 0.5, 0.12, S_vector[i]);
        CPrice4.push_back(EO4c.CallPrice());
        PPrice4.push_back(EO4c.PutPrice());
    }

    for (int i =0; i!= S_vector.size(); i++)
    {
        cout << "Batch 1: S = " << S_vector[i] << " ,Call Price = " << CPrice1[i] << ", Put Price = " << PPrice1[i] << endl;
        cout << "Batch 2: S = " << S_vector[i] << " ,Call Price = " << CPrice2[i] << ", Put Price = " << PPrice2[i] << endl;
        cout << "Batch 3: S = " << S_vector[i] << " ,Call Price = " << CPrice3[i] << ", Put Price = " << PPrice3[i] << endl;
        cout << "Batch 4: S = " << S_vector[i] << " ,Call Price = " << CPrice4[i] << ", Put Price = " << PPrice4[i] << endl;
        cout << endl;
    }


    cout << "Part d)" << endl;
    // D
    vector<double> T_array = MeshArray(1, 50, 1);
    vector<double> sig_array = MeshArray(1, 50, 1);
    vector<double> K_array = MeshArray(51, 100, 1);

    vector<vector<double>> MatrixParameters;
    MatrixParameters.push_back(T_array);
    MatrixParameters.push_back(sig_array);
    MatrixParameters.push_back(K_array);

    MatrixPricer(MatrixParameters);


    // Option Sensitivities a.)
    cout << "Option Sensitivities, aka the Greeks" << endl;
    double b = 0;
    EuropeanOption EuropeanOption1 = EuropeanOption(0.5, 100, 0.36, 0.1, 105);
    cout << "Delta of Call Option = " << EuropeanOption1.CallDelta(b) << endl;
    EuropeanOption1.toggle();
    cout << "Delta of Put Option = " << EuropeanOption1.PutDelta(b) << endl;
    EuropeanOption1.toggle();

    //EuropeanOption EuropeanOption2 = EuropeanOption(0.5, 100, 0.36, 0.1, 105);
    cout << "Gamma of Call Option = " << EuropeanOption1.CallGamma(b) << endl;
    EuropeanOption1.toggle();
    cout << "Gamma of Put Option = " << EuropeanOption1.PutGamma(b) << endl;
    EuropeanOption1.toggle();

    cout << endl;
    cout << "Part b)" << endl;
    // b.)
    //double b = 0;
    //vector<double> S_vector = MeshArray(10, 50, 1);
    for (int i =0; i!= S_vector.size(); i++)
    {
        EuropeanOption EO_S = EuropeanOption(0.5, 100, 0.36, 0.1, S_vector[i]);
        cout << "S = " <<  S_vector[i] << ": Call Price Delta = " << EO_S.CallDelta(b) << endl;
        EO_S.toggle();
        cout << "    " <<  S_vector[i] << ": Put Price Delta = " << EO_S.PutDelta(b) << endl;
        EO_S.toggle();
        cout << endl;
    }

    cout << "Part c)" << endl;
    //c.)
    cout << endl;
    //double b = 0;
    vector<double> T_vector = MeshArray(25, 75, 1);
    vector<double> K_vector = MeshArray(50, 100, 1);
    vector<double> sig_vector = MeshArray(1, 51, 1);

    vector<vector<double>> MatrixParameters1;
    MatrixParameters1.push_back(T_vector);
    MatrixParameters1.push_back(K_vector);
    MatrixParameters1.push_back(sig_vector);

    cout << "Gamma:" << endl;
    GreeksMatrixPricer(MatrixParameters1, b, "Gamma");
    cout << "Delta:" << endl;
    GreeksMatrixPricer(MatrixParameters1, b, "Delta");


    // d.)
    vector<double> h_array = MeshArray(1, 10, 1);
    vector<double> DeltaVec_Call, DeltaVec_Put;

    //double b = 0.0;
    cout << endl;
    cout.precision(6);
    cout << "Part d.)Using divided differences:" << endl;
    cout << "Delta and Gamma for Call Option" << endl;
    for (int i = 0; i != h_array.size(); i++ )
    {
        double V_s_plus = EuropeanOption(0.5, 100, 0.36, 0.1,105 + h_array[i], 0).CallPrice();
        double V_s_minus = EuropeanOption(0.5, 100, 0.36, 0.1,105 - h_array[i], 0).CallPrice();
        double V_s = EuropeanOption(0.5, 100, 0.36, 0.1,105, 0).CallPrice();

        double result1 = (V_s_plus - V_s_minus) / (2 * h_array[i]) ;
        double result2 = (V_s_plus - (2*V_s) + V_s_minus) / (pow(h_array[i],2));

        cout << "h = " << h_array[i] <<  ", Call Option: Delta = " << result1 << " ,Gamma = " << result2 << endl;
    }

    cout << endl;
    cout << "Delta and Gamma for Put Option" << endl;
    for (int i = 0; i != h_array.size(); i++ )
    {
        double V_s_plus = EuropeanOption(0.5, 100, 0.36, 0.1,105 + h_array[i], 0).PutPrice();
        double V_s_minus = EuropeanOption(0.5, 100, 0.36, 0.1,105 - h_array[i], 0).PutPrice();
        double V_s = EuropeanOption(0.5, 100, 0.36, 0.1,105, 0).PutPrice();

        double result1 = (V_s_plus - V_s_minus) / (2 * h_array[i]) ;
        double result2 = (V_s_plus - (2*V_s) + V_s_minus) / (pow(h_array[i],2));

        cout << "h = " << h_array[i] <<  ", Put  Option: Delta = " << result1 << " ,Gamma = " << result2 << endl;
    }

    return 0;

}

