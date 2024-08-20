#ifndef ELECTRONICDENSITY_HPP
#define ELECTRONICDENSITY_HPP

#include "ResultCalculation.hpp"

class ElectronicDensity
{
    public:
    ElectronicDensity(SampleInfo* value);
    ~ElectronicDensity();
    double fermiValue(double energy);
    double density(double energy, double P);
    double deltaKz();

    private:
    double thickness;
    SampleInfo* results;
};

#endif //ELECTRONICDENSITY_HPP