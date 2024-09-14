#include "Data.hpp"
#include "ReadDataIntMock.hpp"
#include "UnitCellInfo.hpp"
#include <cmath>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

class CellInfoTest : public ::testing::Test
{
  protected:
    ReadDataIntMock* data;
    UnitCellInfo* cellInfo;

    void SetUp()
    {
        data = new ReadDataIntMock();
        cellInfo = new UnitCellInfo(data);
    }

    void TearDown()
    {
        delete cellInfo;
        delete data;
    }
};

TEST_F(CellInfoTest, SetValueTest)
{
    std::vector<ElementData> mockCellData = {
        {"Fe", 26, "BCC", 2.87, 2.87, 2.87, 2}};

    EXPECT_CALL(*data, getCellValue())
        .WillOnce(::testing::Return(mockCellData));

    cellInfo->setValue();

    EXPECT_EQ(cellInfo->cellVolume(), std::pow(2.87, 3));
}

TEST_F(CellInfoTest, CellVolumeBccTest)
{
    std::vector<ElementData> mockCellData = {
        {"Fe", 26, "BCC", 2.87, 2.87, 2.87, 2}};

    EXPECT_CALL(*data, getCellValue())
        .WillOnce(::testing::Return(mockCellData));

    cellInfo->setValue();
    double volume = cellInfo->cellVolume();

    EXPECT_DOUBLE_EQ(volume, std::pow(2.87, 3));
}

TEST_F(CellInfoTest, CellVolumeHcpTest)
{
    std::vector<ElementData> mockCellData = {
        {"Mg", 12, "HCP", 3.21, 3.21, 5.21, 2}};

    EXPECT_CALL(*data, getCellValue())
        .WillOnce(::testing::Return(mockCellData));

    cellInfo->setValue();
    double volume = cellInfo->cellVolume();

    EXPECT_DOUBLE_EQ(volume,
                     std::pow(3.21, 2) * 5.21 * (3 * sqrt(3)) / 2);
}

TEST_F(CellInfoTest, CellVolumeInvalidTypeTest)
{
    std::vector<ElementData> mockCellData = {
        {"Xe", 54, "X", 4.0, 4.0, 4.0, 2}};

    EXPECT_CALL(*data, getCellValue())
        .WillOnce(::testing::Return(mockCellData));

    cellInfo->setValue();
    double volume = cellInfo->cellVolume();

    EXPECT_DOUBLE_EQ(volume, -1);
}

TEST_F(CellInfoTest, ElectronDensityTest)
{
    std::vector<ElementData> mockCellData = {
        {"Fe", 26, "BCC", 2.87, 2.87, 2.87, 2}};

    EXPECT_CALL(*data, getCellValue())
        .WillOnce(::testing::Return(mockCellData));

    cellInfo->setValue();
    int density = cellInfo->electronDensity();

    EXPECT_EQ(density, static_cast<int>(2 / std::pow(2.87, 3)));
}
