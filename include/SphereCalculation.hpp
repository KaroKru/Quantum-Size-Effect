#ifndef SPHERECALCULATION_HPP
#define SPHERECALCULATION_HPP

#include "SampleInfo.hpp"
#include "ResultCalculation.hpp"
#include "CalculationInt.hpp"
#include <vector>

struct SampleData
{
    double samThickness = 0;
    double samWaveVec = 0;
    double samNumOfSubbands = 0;
    double samStatestDensity = 0;
    double samElectEnergy = 0;
};

class SphereCalculation : public CalculationInt
{
    public:
    //constructor
    SphereCalculation(SampleInfo* sampleInf, ResultCalculation* calculationValues);
    //copy constructor
    SphereCalculation(const SphereCalculation &oth) = delete;
    //move constructor
    SphereCalculation(SphereCalculation &&oth) = delete;
    //copy operator 
    SphereCalculation& operator=(const SphereCalculation &oth) = delete;
    //move operator
    SphereCalculation& operator=(SphereCalculation &&oth) = delete;
    //destructor
    ~SphereCalculation() override;

    void calculation() override;
    void saved() override;

    private:
    SampleInfo* sampleResult;
    ResultCalculation* calculationResults;
    std::vector<SampleData> data;
};


#endif //SPHERECALCULATION_HPP