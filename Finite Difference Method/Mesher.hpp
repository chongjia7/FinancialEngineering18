#include "UtilitiesDJD\VectorsAndMatrices\Vector.cpp"
#include <vector>
using namespace std;

class Mesher
{
public:
		double a, b;	// In space

		Mesher()
		{
			a =0.0; b = 1.0;
		}

		Mesher (double A, double B)
		{ // Describe the domain of integration

			a = A;
			b = B;
		}

		Vector<double, long> xarr(int J)
		{
			// NB Full array (includes end points)

			double h = (b - a) / double (J);
			
			int size = J+1;
			int start = 1;

			Vector<double, long> result(size, start);
			result[result.MinIndex()] = a;

			for (int j = result.MinIndex()+1; j <= result.MaxIndex(); j++)
			{
				result[j] = result[j-1] + h;
			}

			return result;
		}

		vector<double> Xarr(int J)
		{ // Return as an STL vector

			// NB Full array (includes end points)

			double h = (b - a) / double (J);
			
			int size = J+1;
			int start = 1;

			vector<double> result(size, start);
			result[0] = a;

			for (int j = 1; j < result.size(); j++)
			{
				result[j] = result[j-1] + h;
			}

			return result;
		}

};