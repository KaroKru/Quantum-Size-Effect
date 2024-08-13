#ifndef READDATA_HPP
#define READDATA_HPP

#include <vector>
#include <iostream>
#include <string>

struct Element
{
    std::string element;
    int atomicNumber;
    std::string unitCellType;
    double xCrystalLength;
    double yCrystalLength;
    double zCrystalLength;
    int electronNumber;
};

struct Sample
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
    ReadData(const ReadData &oth);
    //move constructor
    ReadData(ReadData &&oth);
    //copy operator
    ReadData& operator=(const ReadData& oth);
    //move operator
    ReadData& operator=(ReadData&& oth);

    //destructor
    ~ReadData();

    void readUserConfig();
    void readDb();
    std::vector<Element> getCellValue();
    std::vector<Sample> getSampleValue();

    private:
    std::vector<Element> unitCell;
    std::vector<Sample> sample;
};

#endif //READDATA_HPP