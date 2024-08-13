#ifndef SPHERECALCULATION_HPP
#define SPHERECALCULATION_HPP

#include "UnitCellInfo.hpp"
#include "SampleInfo.hpp"

struct SavedData
{
    double Lz;
    double kF;
    double numP;
    double dos;
    double eT;
};

class SphereCalculation
{
    public:
    SphereCalculation(UnitCellInfo* cellInfo, SampleInfo* sampleInfo);
    ~SphereCalculation();

    double deltaKz(double L);
    int nrElectrons();
    double sum(double P);
    double fermiSphere(double P, double L);
    double DOSFermi(double P, double L);
    double sum2(double P);
    double totalEnergy(double P, double L);
    double totalEnergyOverElectronNumber(double P, double L);
    void calculation();
    void saved();

    private:
    UnitCellInfo* cell;
    SampleInfo* sample;
    std::vector<SavedData> data;
};


#endif //SPHERECALCULATION_HPP