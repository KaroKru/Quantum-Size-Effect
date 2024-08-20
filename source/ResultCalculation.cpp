#include "ResultCalculation.hpp"
#include <cmath>

ResultCalculation::ResultCalculation(UnitCellInfo* cellInfo, SampleInfo* sampleInfo)
{
    cell = cellInfo;
    sample = sampleInfo;
}

ResultCalculation::~ResultCalculation()
{

}

double ResultCalculation::deltaKz(double L)
{
    double kZ = M_PI / L;
    return kZ;
}

double ResultCalculation::sum(double P)
{
    double s = P * (P + 1) * (2 * P + 1) / 6;
    return s;
}

double ResultCalculation::fermiSphere(double P, double L)
{
    const int eDensity = cell->electronDensity();
    double kF = 1 / P * (2 * M_PI * L * eDensity + sum(P) * pow((M_PI/L), 2));
    return kF;
}

double ResultCalculation::DOSFermi(double P, double L)
{
    double dos = (MASS * P) / (M_PI * pow(PLANCK_VALUE, 2) * L);
    return dos;
}

double ResultCalculation::sum2(double P)
{
    double s2 = P * (P + 1) * (2 * P + 1) * (3 * pow(P, 2) + 3 * P - 1) / 30;
    return s2;
}

double ResultCalculation::totalEnergy(double P, double kF, double L)
{
    double value = ((pow(PLANCK_VALUE, 2))/(8 * M_PI * MASS * L)) * (P * pow(kF, 4) - sum2(P) * (pow((M_PI / L),4)));
    return value;
}

double ResultCalculation::totalEnergyOverElectronNumber(double P, double kF, double L) 
{
	double val = totalEnergy(P, kF, L) / cell->electronDensity();
    return val;
}