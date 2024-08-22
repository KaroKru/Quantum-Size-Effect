#include "SphereCalculation.hpp"
#include <iostream>
#include <cmath>
#include <fstream>

SphereCalculation::SphereCalculation(SampleInfo* sampleInf, ResultCalculation* calculationValues)
{
    sampleResult = sampleInf;
    calculationResults = calculationValues;
}

SphereCalculation::~SphereCalculation()
{

}

void SphereCalculation::calculation()
{ 
    SampleData sampleDataInfo;

    int maxStepsNum = 2802;
    double thicknessStep = 0.001;
    double energyStep = 0.01;
    double pInitialValue = 1;
    double numOfP = 0;
    double thickness = sampleResult->getSampleThickness();

    for (int i = 1; i < maxStepsNum; i++)
    {
        double fermiWaveVector = std::sqrt(calculationResults->fermiSphere(
            pInitialValue, thickness));
        numOfP = fermiWaveVector / calculationResults->deltaZWaveVector(thickness);

        if (pInitialValue < static_cast<int>(numOfP))
        {
            pInitialValue += 1;
        }

        sampleDataInfo.samThickness = thickness;
        sampleDataInfo.samWaveVec = fermiWaveVector;
        sampleDataInfo.samNumOfSubbands = pInitialValue;
        sampleDataInfo.samStatestDensity = calculationResults->densityOfStates(
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
        std::cerr << "Problem with opening file" << std::endl;
        throw std::runtime_error("Problem with opening file");
    }
    else
    {
        for (const auto &value: data)
        {
            dataFile << value.samThickness << "," << value.samWaveVec << "," << 
            value.samNumOfSubbands << "," << value.samStatestDensity << "," << 
            value.samElectEnergy << std::endl;
        }
        std::cerr << "Saving data" << std::endl;
        dataFile.close();
    }
}