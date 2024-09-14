#ifndef READDATAINT_HPP
#define READDATAINT_HPP

#include "Data.hpp"
#include <vector>

class ReadDataInt
{
  public:
    virtual ~ReadDataInt() = default;
    virtual void readUserConfig() = 0;
    virtual void readCellValues() = 0;
    virtual std::vector<ElementData> getCellValue() = 0;
    virtual std::vector<ConfigData> getSampleValue() = 0;
};

#endif // READDATAINT_HPP