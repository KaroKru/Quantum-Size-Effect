#ifndef READDATA_HPP
#define READDATA_HPP

#include <iostream>
#include <vector>
#include <string>

struct ElementData
{
    std::string elementSymbol;
    int atomicNumber;
    std::string unitCellType;
    double xCrystalLength;
    double yCrystalLength;
    double zCrystalLength;
    int electronNumber;
};

struct ConfigData
{
    std::string element;
    double xLength;
    double yLength;
    double zLength; //sample thickness
};

class ReadData
{
    public:
    //constructor
    ReadData();
    //copy constructor
    ReadData(const ReadData &oth) = delete;
    //move constructor
    ReadData(ReadData &&oth) = delete;
    //copy operator
    ReadData& operator=(const ReadData& oth) = delete;
    //move operator
    ReadData& operator=(ReadData&& oth) = delete;

    //destructor
    ~ReadData();

    void readUserConfig();
    void readCellValues();
    std::vector<ElementData> getCellValue();
    std::vector<ConfigData> getSampleValue();

    private:
    std::vector<ElementData> unitCell;
    std::vector<ConfigData> sample;
};

#endif //READDATA_HPP