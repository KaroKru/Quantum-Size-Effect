#ifndef ELECTRONICDENSITY_HPP
#define ELECTRONICDENSITY_HPP

#include "ResultCalculation.hpp"

class ElectronicDensity
{
    public:
    ElectronicDensity(SampleInfo* sampleValue);
    ~ElectronicDensity();
    double fermiValue(double energy);
    double densityOfStates(double energy, double numOfSubbands);
    double deltaZWaveVector();

    private:
    double thickness = 0;
    SampleInfo* sampleResults;
};

#endif //ELECTRONICDENSITY_HPP