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
    //constructor
    ResultCalculation(UnitCellInfo* cellInfo, SampleInfo* sampleInfo);
    //copy constructor
    ResultCalculation(const ResultCalculation &oth) = delete;
    //move constructor
    ResultCalculation(ResultCalculation &&oth) = delete;
    //copy operator
    ResultCalculation& operator=(const ResultCalculation &oth) = delete;
    //move operator
    ResultCalculation& operator=(ResultCalculation &&oth) = delete; 
    //destructor
    ~ResultCalculation();

    static double deltaZWaveVector(double thickness);
    static double sum(double subbandsNum);
    double fermiSphere(double subbandsNum, double thickness);
    static double densityOfStates(double subbandsNum, double thickness);
    static double sum2(double subbandsNum);
    static double totalEnergy(double subbandsNum, double fermiWaveVector, double thickness);
    double totalEnergyOverElectronNumber(double subbandsNum, double fermiWaveVector, double thickness);

    private:
    UnitCellInfo* cellResults;
    SampleInfo* sampleResults;
};

#endif //RESULTCALCULATION_HPP