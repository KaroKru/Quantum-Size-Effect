#include "SphereCalculation.hpp"
#include <iostream>
#include <cmath>
#include <fstream>

SphereCalculation::SphereCalculation(SampleInfo* sampleInf, ResultCalculation* calculation)
{
    info = sampleInf;
    results = calculation;
}

SphereCalculation::~SphereCalculation()
{

}

void SphereCalculation::calculation()
{ 
    SavedData savedInfo;
    int maxNr = 2802;
    double thicknessStep = 0.001;
    double energyStep = 0.01;
    double p = 1;
    double P = 0;
    double L = info->getSampleThickness();

    for (int i = 1; i < maxNr ; i++)
    {
        double kF = std::sqrt(results->fermiSphere(p, L));
        P = kF / results->deltaKz(L);

        if (p < int(P))
        {
            p += 1;
        }

        savedInfo.Lz = L;
        savedInfo.kF = kF;
        savedInfo.numP = p;
        savedInfo.dos = results->DOSFermi(p, L);
        savedInfo.eT = results->totalEnergyOverElectronNumber(p, kF, L);
        
        data.push_back(savedInfo);

        L += thicknessStep;
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
        for (const auto &i: data)
        {
            dataFile << i.Lz << "," << i.kF << "," << i.numP << "," << i.dos << "," << i.eT << std::endl;
        }
        std::cerr << "Saving data" << std::endl;
        dataFile.close();
    }
}