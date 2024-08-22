#include "ElectronicDensity.hpp"
#include <cmath>

ElectronicDensity::ElectronicDensity(SampleInfo* sampleValue)
{
    sampleResults = sampleValue;
    thickness = sampleResults->getSampleThickness();
}

ElectronicDensity::~ElectronicDensity()
{

}

double ElectronicDensity::fermiValue(double energy)
{
    double fermiWaveVector = sqrt((2 * MASS *energy) / (pow(PLANCK_VALUE, 2)));
    return fermiWaveVector;
}

double ElectronicDensity::densityOfStates(double energy, double numOfSubbands)
{
    double statesDensity = (MASS / (M_PI * (pow(PLANCK_VALUE, 2)) * thickness)) * numOfSubbands;
    return statesDensity;
}

double ElectronicDensity::deltaZWaveVector()
{
    double zWaveVector = M_PI / thickness;
    return zWaveVector;
}