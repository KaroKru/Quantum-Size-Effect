#ifndef SAMPLEINFO_HPP
#define SAMPLEINFO_HPP

#include "ReadData.hpp"
#include <vector>

class SampleInfo
{
    public:
    SampleInfo(ReadData* dataValues);
    ~SampleInfo();

    double sampleArea();
    void setValue();
    double getSampleThickness();

    private:
    ReadData* dataReaded;
    std::vector<ConfigData> userData;
};

#endif //SAMPLEINFO_HPP