#ifndef SAMPLEINFO_HPP
#define SAMPLEINFO_HPP

#include "ReadData.hpp"

class SampleInfo
{
    public:
    SampleInfo(ReadData* data);
    ~SampleInfo();

    double sampleArea();
    double sampleVolume();
    void setValue();
    double getSampleThickness();

    private:
    ReadData* dataReaded;
    std::vector<Sample> info;
};

#endif //SAMPLEINFO_HPP