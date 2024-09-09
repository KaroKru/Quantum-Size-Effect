#ifndef READDATA_HPP
#define READDATA_HPP

#include <iostream>
#include <string>
#include <vector>

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

class ReadData
{
  public:
    // constructor
    ReadData();
    // copy constructor
    ReadData(const ReadData& oth) = delete;
    // move constructor
    ReadData(ReadData&& oth) = delete;
    // copy operator
    ReadData& operator=(const ReadData& oth) = delete;
    // move operator
    ReadData& operator=(ReadData&& oth) = delete;
    // destructor
    ~ReadData();

    void readUserConfig();
    void readCellValues();
    std::vector<ElementData> getCellValue();
    std::vector<ConfigData> getSampleValue();

  private:
    std::vector<ElementData> unitCell;
    std::vector<ConfigData> sample;
};

#endif // READDATA_HPP