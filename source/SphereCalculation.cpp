#include "SphereCalculation.hpp"
#include <cmath>
#include <iostream>
#include <fstream>

#define LIGHT_SPEED (299792458 * (pow(10, 9)))
#define PLANCK_VALUE (6.58 * (pow(10, -16)))
#define MASS ((511000) / (pow(LIGHT_SPEED, 2)))

SphereCalculation::SphereCalculation(UnitCellInfo* cellInfo, SampleInfo* sampleInfo)
{
    cell = cellInfo;
    sample = sampleInfo;
}

SphereCalculation::~SphereCalculation()
{

}

double SphereCalculation::deltaKz(double L)
{
    double kZ = M_PI  / L;
    return kZ;
}

int SphereCalculation::nrElectrons()
{
    int number = cell->cellVolume() * cell->electronDensity();
    return number;
}

double SphereCalculation::sum(double P)
{
    double s = (P * (P + 1) * (2 * P + 1)) / 6;
    return s;
}

double SphereCalculation::fermiSphere(double P, double L)
{
    double kF = sqrt((1 / P) * (2 * M_PI * L * cell->electronDensity() + sum(P) * pow(M_PI, 2)));
    return kF;
}

double SphereCalculation::DOSFermi(double P, double L)
{
    double dos = (MASS * P) / (M_PI * pow(PLANCK_VALUE, 2) * L);
    return dos;
}

double SphereCalculation::sum2(double P)
{
    double s2 = ((P * (P + 1) * (2 * P + 1) * (3 * pow(P, 2) + 3 * P - 1)) / 30);
    return s2;
}

double SphereCalculation::totalEnergy(double P, double L)
{
    double value = ((pow(PLANCK_VALUE, 2)) / (8 * M_PI * MASS * L)) * (P * pow(fermiSphere(P, L), 4) - sum2(P) * pow(M_PI * L, 4));
    return value;
}

double SphereCalculation::totalEnergyOverElectronNumber(double P, double L) 
{
	double val = totalEnergy(P, L) / nrElectrons();
    return val;
}

void SphereCalculation::calculation()
{   
    SavedData savedInfo;
    int maxNr = 10000;
    double step = 0.003;
    double p = 1;
    double P = 0;
    double L = sample->getSampleThickness();

    for (int i = 1; i < maxNr ; i++)
    {
        double P = std::sqrt(fermiSphere(P, L)) / deltaKz(L);

        if (p < (int)P)
        {
            p += 1;
        }

        savedInfo.Lz = L;
        savedInfo.kF = fermiSphere(p, L);
        savedInfo.numP = p;
        savedInfo.dos = DOSFermi(p, L);
        savedInfo.eT = totalEnergy(p, L);
        
        data.push_back(savedInfo);

        L += step;
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