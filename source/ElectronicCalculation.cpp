#include "ElectronicCalculation.hpp"
#include <iostream>
#include <fstream>

ElectronicCalculation::ElectronicCalculation(std::unique_ptr<ElectronicDensity> electronicDensity) : densityResult(std::move(electronicDensity))
{

}

ElectronicCalculation::~ElectronicCalculation()
{
    
}

void ElectronicCalculation::calculation()
{
    ElectronicData electronicDataInfo;

    const int numSteps = 2802;
    const double energyStep = 0.01;
    double pInitialValue = 1;
    double numOfP = 0;
    double energyValue = 0;

    for (int i = 1; i < numSteps ; i++)
    {
        double fermiWaveVector = densityResult->fermiValue(energyValue);
        numOfP = fermiWaveVector / densityResult->deltaZWaveVector();

        if (pInitialValue < static_cast<int>(numOfP))
        {
            pInitialValue += 1;
        }

        electronicDataInfo.density = densityResult->densityOfStates(energyValue, pInitialValue);
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
        std::cerr << "Problem with opening file\n";
        throw std::runtime_error("Problem with opening file");
    }
    
    for (const auto &value: electronicInfo)
    {
        dataFile << value.density << "," << value.energy << "\n";
    }
    std::cerr << "Saving data\n";
    dataFile.close();
}