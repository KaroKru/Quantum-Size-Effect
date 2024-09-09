#include "UnitCellInfo.hpp"
#include <cmath>
#include <iostream>

UnitCellInfo::UnitCellInfo(ReadData* readed) : cellData(readed)
{
}

UnitCellInfo::~UnitCellInfo()
{
}

void UnitCellInfo::setValue()
{
    elementInfo = cellData->getCellValue();
}

double UnitCellInfo::cellVolume()
{
    double volume = 0;
    std::string cellType = elementInfo[0].unitCellType;

    if (cellType == "BCC" or cellType == "FCC" or cellType == "SC")
    {
        volume = std::pow(elementInfo[0].xCrystalLength, 3);
    }
    else if (cellType == "HCP")
    {
        const double constVal = (3 * sqrt(3)) / 2;
        volume = std::pow(elementInfo[0].xCrystalLength, 2) *
                 elementInfo[0].zCrystalLength * constVal;
    }
    else
    {
        return -1;
    }

    return volume;
}

int UnitCellInfo::electronDensity()
{
    double sampleVolume = cellVolume();

    int density = static_cast<int>(elementInfo[0].electronNumber /
                                   sampleVolume);

    return density;
}
