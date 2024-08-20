#ifndef ELECTRONICCALCULATION_HPP
#define ELECTRONICCALCULATION_HPP

#include "ElectronicDensity.hpp"
#include <vector>

struct ElectronicData
{
    double density;
    double energy;
};

class ElectronicCalculation
{
    public:
    ElectronicCalculation(ElectronicDensity* density);
    ~ElectronicCalculation();

    void calculation();
    void saved();

    private:
    ElectronicDensity* eDensity;
    std::vector<ElectronicData> electronicInfo;
};

#endif //ELECTRONICCALCULATION_HPP