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
    ReadData* data;
    std::vector<Element> elementInfo;
};


#endif //UNITCELLINFO_HPP