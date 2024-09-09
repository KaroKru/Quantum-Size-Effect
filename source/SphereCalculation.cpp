#include "SphereCalculation.hpp"
#include <iostream>
#include <cmath>
#include <fstream>

SphereCalculation::SphereCalculation(SampleInfo* sampleInf, ResultCalculation* calculationValues) 
: sampleResult(sampleInf), calculationResults(calculationValues)
{
    
}

SphereCalculation::~SphereCalculation()
{

}

void SphereCalculation::calculation()
{ 
    SampleData sampleDataInfo;

    const int maxStepsNum = 2802;
    const double thicknessStep = 0.001;
    const double energyStep = 0.01;
    double pInitialValue = 1;
    double numOfP = 0;
    double thickness = sampleResult->getSampleThickness();

    for (int i = 1; i < maxStepsNum; i++)
    {
        double fermiWaveVector = std::sqrt(calculationResults->fermiSphere(
            pInitialValue, thickness));
        numOfP = fermiWaveVector / ResultCalculation::deltaZWaveVector(thickness);

        if (pInitialValue < static_cast<int>(numOfP))
        {
            pInitialValue += 1;
        }

        sampleDataInfo.samThickness = thickness;
        sampleDataInfo.samWaveVec = fermiWaveVector;
        sampleDataInfo.samNumOfSubbands = pInitialValue;
        sampleDataInfo.samStatestDensity = ResultCalculation::densityOfStates(
            pInitialValue, thickness);
        sampleDataInfo.samElectEnergy = calculationResults->totalEnergyOverElectronNumber(
            pInitialValue, fermiWaveVector, thickness);
        
        data.push_back(sampleDataInfo);

        thickness += thicknessStep;
    }
}

void SphereCalculation::saved()
{
    std::ofstream dataFile("savedData.txt", std::ios::out);

    if (!dataFile.is_open())
    {
        std::cerr << "Problem with opening file\n";
        throw std::runtime_error("Problem with opening file");
    }
    
    for (const auto &value: data)
    {
        dataFile << value.samThickness << "," << value.samWaveVec << "," << 
        value.samNumOfSubbands << "," << value.samStatestDensity << "," << 
        value.samElectEnergy << "\n";
    }
    std::cerr << "Saving data\n";
    dataFile.close();
}