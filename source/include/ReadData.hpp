#ifndef READDATA_HPP
#define READDATA_HPP

#include "Data.hpp"
#include "ReadDataInt.hpp"
#include <iostream>
#include <string>
#include <vector>

class ReadData : public ReadDataInt
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

    void readUserConfig() override;
    void readCellValues() override;
    std::vector<ElementData> getCellValue() override;
    std::vector<ConfigData> getSampleValue() override;

  private:
    std::vector<ElementData> unitCell;
    std::vector<ConfigData> sample;
};

#endif // READDATA_HPP