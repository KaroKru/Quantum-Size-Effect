#include "SampleInfo.hpp"

SampleInfo::SampleInfo(ReadData* data)
{
    dataReaded = data;
}

SampleInfo::~SampleInfo()
{

}

void SampleInfo::setValue()
{
    info = dataReaded->getSampleValue();
}

double SampleInfo::getSampleThickness()
{
    double Lz = info[0].zLength;
    return Lz;
}

double SampleInfo::sampleArea()
{
    double area = info[0].xLength * info[0].yLength;
    return area;
}

double SampleInfo::sampleVolume()
{
    double volume = sampleArea() * info[0].zLength;
    return volume;
}