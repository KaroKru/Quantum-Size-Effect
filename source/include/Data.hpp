#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct SampleData
{
    double samThickness = 0;
    double samWaveVec = 0;
    double samNumOfSubbands = 0;
    double samStatestDensity = 0;
    double samElectEnergy = 0;
};

struct ElementData
{
    std::string elementSymbol;
    int atomicNumber = 0;
    std::string unitCellType;
    double xCrystalLength = 0;
    double yCrystalLength = 0;
    double zCrystalLength = 0;
    int electronNumber = 0;
};

struct ConfigData
{
    std::string element;
    double xLength = 0;
    double yLength = 0;
    double zLength = 0; // sample thickness
};

#endif // DATA_HPP