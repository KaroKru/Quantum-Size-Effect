#ifndef ELECTRONICCALCULATION_HPP
#define ELECTRONICCALCULATION_HPP

#include "ElectronicDensity.hpp"
#include "CalculationInt.hpp"
#include <vector>

struct ElectronicData
{
    double density;
    double energy;
};

class ElectronicCalculation : public CalculationInt
{
    public:
    ElectronicCalculation(ElectronicDensity* electronicDensity);
    ~ElectronicCalculation();

    void calculation() override;
    void saved() override;

    private:
    ElectronicDensity* densityResult;
    std::vector<ElectronicData> electronicInfo;
};

#endif //ELECTRONICCALCULATION_HPP