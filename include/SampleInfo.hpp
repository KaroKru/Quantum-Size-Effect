#ifndef SAMPLEINFO_HPP
#define SAMPLEINFO_HPP

#include "ReadData.hpp"
#include <vector>

class SampleInfo
{
    public:
    //constructor
    SampleInfo(ReadData* dataValues);
    //copy constructor
    SampleInfo(const SampleInfo &oth) = delete;
    //move constructor 
    SampleInfo(SampleInfo &&oth) = delete;
    //copy operator
    SampleInfo& operator=(const SampleInfo &oth) = delete;
    //move operator
    SampleInfo& operator=(SampleInfo &&oth) = delete;
    //destructor
    ~SampleInfo();

    double sampleArea();
    void setValue();
    double getSampleThickness();

    private:
    ReadData* dataReaded;
    std::vector<ConfigData> userData;
};

#endif //SAMPLEINFO_HPP