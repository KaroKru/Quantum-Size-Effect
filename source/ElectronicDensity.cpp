#include "ElectronicDensity.hpp"
#include <cmath>

ElectronicDensity::ElectronicDensity(SampleInfo* value)
{
    results = value;
    thickness = results->getSampleThickness();
}

ElectronicDensity::~ElectronicDensity()
{

}

double ElectronicDensity::fermiValue(double energy)
{
    double kF = sqrt((2 * MASS *energy) / (pow(PLANCK_VALUE, 2)));
    return kF;
}

double ElectronicDensity::density(double energy, double P)
{
    double dos = (MASS / (M_PI * (pow(PLANCK_VALUE, 2)) * thickness)) * P;
    return dos;
}

double ElectronicDensity::deltaKz()
{
    double kZ = M_PI / thickness;
    return kZ;
}