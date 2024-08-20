#ifndef SPHERECALCULATION_HPP
#define SPHERECALCULATION_HPP

#include "SampleInfo.hpp"
#include "ResultCalculation.hpp"
#include <vector>

struct SavedData
{
    double Lz;
    double kF;
    double numP;
    double dos;
    double eT;
};

class SphereCalculation
{
    public:
    SphereCalculation(SampleInfo* sampleInf, ResultCalculation* calculation);
    ~SphereCalculation();

    void calculation();
    void saved();

    private:
    SampleInfo* info;
    ResultCalculation* results;
    std::vector<SavedData> data;
};


#endif //SPHERECALCULATION_HPP