#ifndef UNITCELLINFO_HPP
#define UNITCELLINFO_HPP

#include "ReadDataInt.hpp"
#include <vector>

class UnitCellInfo
{
  public:
    // constructor
    UnitCellInfo(ReadDataInt* readed);
    // copy constructor
    UnitCellInfo(const UnitCellInfo& oth) = delete;
    // move constructor
    UnitCellInfo(UnitCellInfo&& oth) = delete;
    // copy operator
    UnitCellInfo& operator=(const UnitCellInfo& oth) = delete;
    // move operator
    UnitCellInfo& operator=(UnitCellInfo&& oth) = delete;
    // destructor
    ~UnitCellInfo();

    double cellVolume();
    int electronDensity();
    void setValue();

  private:
    ReadDataInt* cellData;
    std::vector<ElementData> elementInfo;
};

#endif // UNITCELLINFO_HPP