#ifndef SAMPLEINFO_HPP
#define SAMPLEINFO_HPP

#include "ReadData.hpp"
#include <vector>

class SampleInfo
{
    public:
    SampleInfo(ReadData* data);
    ~SampleInfo();

    double sampleArea();
    void setValue();
    double getSampleThickness();

    private:
    ReadData* dataReaded;
    std::vector<Sample> info;
};

#endif //SAMPLEINFO_HPP