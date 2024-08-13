#include <fstream>
#include "ReadData.hpp"
#include <sstream> 
#include <cmath>

ReadData::ReadData()
{
   
}

ReadData::~ReadData()
{

}

void ReadData::readUserConfig()
{
    std::ifstream readData("../source/configuration/values.txt");

    if (!readData.is_open())
    {
        throw std::runtime_error("Problem with opening the user configuration file");
    }
    
    std::string line;
    int lineNumber = 0;

    while (getline(readData, line)) 
    {
        std::stringstream ss(line);
        Sample sampleData;

        std::getline(ss, sampleData.element, ',');
        ss>> sampleData.xLength;
        ss.ignore(1);
        ss >> sampleData.yLength;
        ss.ignore(1);
        ss >> sampleData.zLength;

        sample.push_back(sampleData);
    }

    readData.close();
}

void ReadData::readDb()
{
    std::ifstream db("../source/configuration/unitCellInfo.txt");

    if (!db.is_open())
    {
        throw std::runtime_error("Problem with opening unit cell information file");
    }

    std::string line;
    int lineNumber = 0;

    while (getline(db, line)) 
    {
       std::string elementName = line.substr(0, line.find(','));

       if (elementName == sample[0].element)
       {
            std::stringstream ss(line);
            Element data;

            std::getline(ss, data.element, ',');
            ss>> data.atomicNumber;
            ss.ignore(1);
            std::getline(ss, data.unitCellType, ',');
            ss >> data.xCrystalLength;
            ss.ignore(1);
            ss >> data.yCrystalLength;
            ss.ignore(1);
             ss >> data.zCrystalLength;
            ss.ignore(1);
            ss >> data.electronNumber;

            unitCell.push_back(data);
       }
    }

    db.close();
}

std::vector<Element> ReadData::getCellValue()
{
    return unitCell;
}

std::vector<Sample> ReadData::getSampleValue()
{
    return sample;
}
