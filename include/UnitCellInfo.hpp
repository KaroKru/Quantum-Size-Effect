#ifndef UNITCELLINFO_HPP
#define UNITCELLINFO_HPP

#include "ReadData.hpp"
#include <vector>

class UnitCellInfo
{
    public:
    UnitCellInfo(ReadData* readed);
    ~UnitCellInfo();

    double cellVolume();
    int electronDensity();
    void setValue();

    private:
    ReadData* cellData;
    std::vector<ElementData> elementInfo;
};


#endif //UNITCELLINFO_HPP