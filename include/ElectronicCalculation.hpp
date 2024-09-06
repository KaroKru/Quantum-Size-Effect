#ifndef ELECTRONICCALCULATION_HPP
#define ELECTRONICCALCULATION_HPP

#include "ElectronicDensity.hpp"
#include "CalculationInt.hpp"
#include <vector>
#include <memory>

struct ElectronicData
{
    double density;
    double energy;
};

class ElectronicCalculation : public CalculationInt
{
    public:
    //constructor
    ElectronicCalculation(std::unique_ptr<ElectronicDensity> electronicDensity);
    //copy constructor
    ElectronicCalculation(const ElectronicCalculation &oth) = delete;
    //move constructor
    ElectronicCalculation(ElectronicCalculation &&oth) = delete;
    //copy operator
    ElectronicCalculation& operator=(const ElectronicCalculation& oth) = delete;
    //move operator 
    ElectronicCalculation& operator=(ElectronicCalculation&& oth) = delete;
    //destructor
    ~ElectronicCalculation();
    
    void calculation() override;
    void saved() override;

    private:
    std::unique_ptr<ElectronicDensity> densityResult;
    std::vector<ElectronicData> electronicInfo;
};

#endif //ELECTRONICCALCULATION_HPP