#ifndef SPHERECALCULATION_HPP
#define SPHERECALCULATION_HPP

#include "SampleInfo.hpp"
#include "ResultCalculation.hpp"
#include "CalculationInt.hpp"
#include <vector>

struct SampleData
{
    double samThickness;
    double samWaveVec;
    double samNumOfSubbands;
    double samStatestDensity;
    double samElectEnergy;
};

class SphereCalculation : public CalculationInt
{
    public:
    SphereCalculation(SampleInfo* sampleInf, ResultCalculation* calculationValues);
    ~SphereCalculation();

    void calculation() override;
    void saved() override;

    private:
    SampleInfo* sampleResult;
    ResultCalculation* calculationResults;
    std::vector<SampleData> data;
};


#endif //SPHERECALCULATION_HPP