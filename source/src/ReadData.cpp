#include "ReadData.hpp"
#include <fstream>
#include <sstream>

ReadData::ReadData()
{
}

ReadData::~ReadData()
{
}

void ReadData::readUserConfig()
{
    std::ifstream sampleValues(
        "../source/src/configuration/values.txt");

    if (!sampleValues.is_open())
    {
        throw std::runtime_error(
            "Problem with opening the user configuration file");
    }

    std::string line;
    int lineNumber = 0;

    while (getline(sampleValues, line))
    {
        std::stringstream readConfig(line);
        ConfigData sampleData;

        std::getline(readConfig, sampleData.element, ',');
        readConfig >> sampleData.xLength;
        readConfig.ignore(1);
        readConfig >> sampleData.yLength;
        readConfig.ignore(1);
        readConfig >> sampleData.zLength;

        sample.push_back(sampleData);
    }

    sampleValues.close();
}

void ReadData::readCellValues()
{
    std::ifstream cellValues(
        "../source/src/configuration/unitCellInfo.txt");

    if (!cellValues.is_open())
    {
        throw std::runtime_error(
            "Problem with opening unit cell information file");
    }

    std::string line;
    int lineNumber = 0;

    while (getline(cellValues, line))
    {
        std::string elementName = line.substr(0, line.find(','));

        if (elementName == sample[0].element)
        {
            std::stringstream readData(line);
            ElementData data;

            std::getline(readData, data.elementSymbol, ',');
            readData >> data.atomicNumber;
            readData.ignore(1);
            std::getline(readData, data.unitCellType, ',');
            readData >> data.xCrystalLength;
            readData.ignore(1);
            readData >> data.yCrystalLength;
            readData.ignore(1);
            readData >> data.zCrystalLength;
            readData.ignore(1);
            readData >> data.electronNumber;

            unitCell.push_back(data);
        }
    }

    cellValues.close();
}

std::vector<ElementData> ReadData::getCellValue()
{
    return unitCell;
}

std::vector<ConfigData> ReadData::getSampleValue()
{
    return sample;
}
