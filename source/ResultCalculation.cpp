#include "ResultCalculation.hpp"
#include <cmath>

ResultCalculation::ResultCalculation(UnitCellInfo* cellInfo, SampleInfo* sampleInfo)
{
    cellResults = cellInfo;
    sampleResults = sampleInfo;
}

ResultCalculation::~ResultCalculation()
{

}

double ResultCalculation::deltaZWaveVector(double thickness)
{
    double ZWaveVector = M_PI / thickness;
    return ZWaveVector;
}

double ResultCalculation::sum(double subbandsNum)
{
    double sumResult = subbandsNum * (subbandsNum + 1) * (2 * subbandsNum + 1) / 6;
    return sumResult;
}

double ResultCalculation::fermiSphere(double subbandsNum, double thickness)
{
    const int eDensity = cellResults->electronDensity();

    double fermiVector = 1 / subbandsNum * (2 * M_PI * thickness * eDensity + sum(subbandsNum) * pow((M_PI/thickness), 2));
    return fermiVector;
}

double ResultCalculation::densityOfStates(double subbandsNum, double thickness)
{
    double statesDensity = (MASS * subbandsNum) / (M_PI * pow(PLANCK_VALUE, 2) * thickness);
    return statesDensity;
}

double ResultCalculation::sum2(double subbandsNum)
{
    double sumVal = subbandsNum * (subbandsNum + 1) * (2 * subbandsNum + 1) * (3 * pow(subbandsNum, 2) + 3 * subbandsNum - 1) / 30;
    return sumVal;
}

double ResultCalculation::totalEnergy(double subbandsNum, double fermiWaveVector, double thickness)
{
    double energyValue = ((pow(PLANCK_VALUE, 2))/(8 * M_PI * MASS * thickness)) * (subbandsNum * pow(fermiWaveVector, 4) - sum2(subbandsNum) * (pow((M_PI / thickness),4)));
    return energyValue;
}

double ResultCalculation::totalEnergyOverElectronNumber(double subbandsNum, double fermiWaveVector, double thickness) 
{
	double electronEnergy = totalEnergy(subbandsNum, fermiWaveVector, thickness) / cellResults->electronDensity();
    return electronEnergy;
}