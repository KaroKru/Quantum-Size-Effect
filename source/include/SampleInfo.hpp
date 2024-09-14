#ifndef SAMPLEINFO_HPP
#define SAMPLEINFO_HPP

#include "Data.hpp"
#include "ReadDataInt.hpp"
#include <vector>

class SampleInfo
{
  public:
    // constructor
    SampleInfo(ReadDataInt* dataValues);
    // copy constructor
    SampleInfo(const SampleInfo& oth) = delete;
    // move constructor
    SampleInfo(SampleInfo&& oth) = delete;
    // copy operator
    SampleInfo& operator=(const SampleInfo& oth) = delete;
    // move operator
    SampleInfo& operator=(SampleInfo&& oth) = delete;
    // destructor
    ~SampleInfo();

    double sampleArea();
    void setValue();
    double getSampleThickness();

  private:
    ReadDataInt* dataReaded;
    std::vector<ConfigData> userData;
};

#endif // SAMPLEINFO_HPP