#include "SampleInfo.hpp"

SampleInfo::SampleInfo(ReadData* dataValues) : dataReaded(dataValues)
{
}

SampleInfo::~SampleInfo()
{
}

void SampleInfo::setValue()
{
    userData = dataReaded->getSampleValue();
}

double SampleInfo::getSampleThickness()
{
    double thickness = userData[0].zLength;
    return thickness;
}

double SampleInfo::sampleArea()
{
    double area = userData[0].xLength * userData[0].yLength;
    return area;
}
