#ifndef SPHERECALCULATION_HPP
#define SPHERECALCULATION_HPP

#include "CalculationInt.hpp"
#include "Data.hpp"
#include "ResultCalculation.hpp"
#include "SampleInfo.hpp"
#include <vector>

class SphereCalculation : public CalculationInt
{
  public:
    // constructor
    SphereCalculation(SampleInfo* sampleInf,
                      ResultCalculation* calculationValues);
    // copy constructor
    SphereCalculation(const SphereCalculation& oth) = delete;
    // move constructor
    SphereCalculation(SphereCalculation&& oth) = delete;
    // copy operator
    SphereCalculation&
    operator=(const SphereCalculation& oth) = delete;
    // move operator
    SphereCalculation& operator=(SphereCalculation&& oth) = delete;
    // destructor
    ~SphereCalculation() override;

    void calculation() override;
    void saved() override;

    std::vector<SampleData> data;

  private:
    SampleInfo* sampleResult;
    ResultCalculation* calculationResults;
};

#endif // SPHERECALCULATION_HPP