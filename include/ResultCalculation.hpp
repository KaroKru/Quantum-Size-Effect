#ifndef RESULTCALCULATION_HPP
#define RESULTCALCULATION_HPP

#include "SampleInfo.hpp"
#include "UnitCellInfo.hpp"

#define LIGHT_SPEED (299792458 * (pow(10, 9)))
#define PLANCK_VALUE (6.58 * (pow(10, -16)))
#define MASS ((511000) / (pow(LIGHT_SPEED, 2)))

class ResultCalculation
{
    public:
    ResultCalculation(UnitCellInfo* cellInfo, SampleInfo* sampleInfo);
    ~ResultCalculation();

    double deltaKz(double L);
    double sum(double P);
    double fermiSphere(double P, double L);
    double DOSFermi(double P, double L);
    double sum2(double P);
    double totalEnergy(double P, double kF, double L);
    double totalEnergyOverElectronNumber(double P, double kF, double L);

    private:
    UnitCellInfo* cell;
    SampleInfo* sample;
};

#endif //RESULTCALCULATION_HPP