#include "ElectronicCalculation.hpp"
#include <iostream>
#include <fstream>

ElectronicCalculation::ElectronicCalculation(ElectronicDensity* density)
{
    eDensity = density;
}

ElectronicCalculation::~ElectronicCalculation()
{
    
}

void ElectronicCalculation::calculation()
{
    ElectronicData electronicDataInfo;
    int numSteps = 2802;
    double energyStep = 0.01;
    double pInitialValue = 1;
    double numOfP = 0;
    double energyValue = 0;

    for (int i = 1; i < numSteps ; i++)
    {
        double fermiWaveVector = eDensity->fermiValue(energyValue);
        numOfP = fermiWaveVector / eDensity->deltaKz();

        if (pInitialValue < static_cast<int>(numOfP))
        {
            pInitialValue += 1;
        }

        electronicDataInfo.density = eDensity->density(energyValue, pInitialValue);
        electronicDataInfo.energy = energyValue;
        
        electronicInfo.push_back(electronicDataInfo);

        energyValue += energyStep;
    }
}

void ElectronicCalculation::saved()
{
    std::ofstream dataFile("electronicData.txt", std::ios::out);

    if (!dataFile.is_open())
    {
        std::cerr << "Problem with opening file" << std::endl;
        throw std::runtime_error("Problem with opening file");
    }
    else
    {
        for (const auto &value: electronicInfo)
        {
            dataFile << value.density << "," << value.energy << std::endl;
        }
        std::cerr << "Saving data" << std::endl;
        dataFile.close();
    }
}