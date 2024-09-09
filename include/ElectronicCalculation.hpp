#ifndef ELECTRONICCALCULATION_HPP
#define ELECTRONICCALCULATION_HPP

#include "CalculationInt.hpp"
#include "ElectronicDensity.hpp"
#include <memory>
#include <vector>

struct ElectronicData
{
    double density = 0;
    double energy = 0;
};

class ElectronicCalculation : public CalculationInt
{
  public:
    // constructor
    ElectronicCalculation(
        std::unique_ptr<ElectronicDensity> electronicDensity);
    // copy constructor
    ElectronicCalculation(const ElectronicCalculation& oth) = delete;
    // move constructor
    ElectronicCalculation(ElectronicCalculation&& oth) = delete;
    // copy operator
    ElectronicCalculation&
    operator=(const ElectronicCalculation& oth) = delete;
    // move operator
    ElectronicCalculation&
    operator=(ElectronicCalculation&& oth) = delete;
    // destructor
    ~ElectronicCalculation() override;

    void calculation() override;
    void saved() override;

  private:
    std::unique_ptr<ElectronicDensity> densityResult;
    std::vector<ElectronicData> electronicInfo;
};

#endif // ELECTRONICCALCULATION_HPP