#include "UtilitiesDJD/RNG/NormalGenerator.hpp"
#include <cmath>



BoostNormal::BoostNormal() : NormalGenerator ()
{
	rng = boost::lagged_fibonacci607();
	nor = boost::normal_distribution<>(0,1);
	myRandom = new boost::variate_generator<boost::lagged_fibonacci607&, boost::normal_distribution<> >
			(rng, nor);

}


// Implement (variant) hook function
double BoostNormal::getNormal() const
{
	return (*myRandom)();
}


BoostNormal::~BoostNormal() 
{

	delete myRandom;
}


