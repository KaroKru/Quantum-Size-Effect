#ifndef ELECTRONICDENSITY_HPP
#define ELECTRONICDENSITY_HPP

#include "ResultCalculation.hpp"

class ElectronicDensity
{
  public:
    // constructor
    ElectronicDensity(SampleInfo* sampleValue);
    // copy costructor
    ElectronicDensity(const ElectronicDensity& oth) = delete;
    // move constructor
    ElectronicDensity(ElectronicDensity&& oth) = delete;
    // copy operator
    ElectronicDensity&
    operator=(const ElectronicDensity& oth) = delete;
    // move operator
    ElectronicDensity& operator=(ElectronicDensity&& oth) = delete;
    // destructor
    ~ElectronicDensity();

    static double fermiValue(double energy);
    double densityOfStates(double energy, double numOfSubbands);
    double deltaZWaveVector();

  private:
    double thickness = 0;
    SampleInfo* sampleResults;
};

#endif // ELECTRONICDENSITY_HPP