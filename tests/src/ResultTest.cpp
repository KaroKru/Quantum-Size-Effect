#include "Data.hpp"
#include "ReadDataIntMock.hpp"
#include "ResultCalculation.hpp"
#include "SampleInfo.hpp"
#include "UnitCellInfo.hpp"
#include <cmath>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

class ResultTest : public ::testing::Test
{
  public:
    ReadDataIntMock* data;
    SampleInfo* sample;
    UnitCellInfo* cellInfo;
    ResultCalculation* resultCalc;

    void SetUp()
    {
        data = new ReadDataIntMock();

        std::vector<ElementData> elementData = {
            {"Si", 14, "FCC", 5.43, 5.43, 5.43, 4}};
        std::vector<ConfigData> sampleData = {{"Si", 2.5, 2.5, 2.5}};

        EXPECT_CALL(*data, getCellValue())
            .WillOnce(::testing::Return(elementData));
        EXPECT_CALL(*data, getSampleValue())
            .WillOnce(::testing::Return(sampleData));

        cellInfo = new UnitCellInfo(data);
        cellInfo->setValue();

        sample = new SampleInfo(data);
        sample->setValue();

        resultCalc = new ResultCalculation(cellInfo, sample);
    }

    void TearDown()
    {
        delete resultCalc;
        delete cellInfo;
        delete sample;
        delete data;
    }
};

TEST_F(ResultTest, DeltaZWaveVectorCalculatesCorrectlyTest)
{
    double thickness = 2.0;
    double expected = M_PI / thickness;

    double result = resultCalc->deltaZWaveVector(thickness);

    EXPECT_DOUBLE_EQ(result, expected);
}

TEST_F(ResultTest, SumCalculatesCorrectlyTest)
{
    double subbandsNum = 3.0;
    double value = 6.0;
    double expected = subbandsNum * (subbandsNum + 1) *
                      (2 * subbandsNum + 1) / value;

    double result = resultCalc->sum(subbandsNum);

    EXPECT_DOUBLE_EQ(result, expected);
}

TEST_F(ResultTest, FermiSphereCalculatesCorrectlyTest)
{
    double subbandsNum = 2.0;
    double thickness = 3.0;

    double expected =
        1 / subbandsNum *
        (2 * M_PI * thickness * cellInfo->electronDensity() +
         resultCalc->sum(subbandsNum) * pow((M_PI / thickness), 2));

    double result = resultCalc->fermiSphere(subbandsNum, thickness);

    EXPECT_DOUBLE_EQ(result, expected);
}

TEST_F(ResultTest, DensityOfStatesCalculatesCorrectlyTest)
{
    double subbandsNum = 2.0;
    double thickness = 3.0;
    double expected = (MASS * subbandsNum) /
                      (M_PI * pow(PLANCK_VALUE, 2) * thickness);

    double result =
        resultCalc->densityOfStates(subbandsNum, thickness);

    EXPECT_DOUBLE_EQ(result, expected);
}

TEST_F(ResultTest, TotalEnergyCalculatesCorrectlyTest)
{
    double subbandsNum = 2.0;
    double fermiWaveVector = 1.5;
    double thickness = 3.0;

    double expected =
        ((pow(PLANCK_VALUE, 2)) / (8 * M_PI * MASS * thickness)) *
        (subbandsNum * pow(fermiWaveVector, 4) -
         resultCalc->sum2(subbandsNum) * pow((M_PI / thickness), 4));

    double result = resultCalc->totalEnergy(
        subbandsNum, fermiWaveVector, thickness);

    EXPECT_DOUBLE_EQ(result, expected);
}

TEST_F(ResultTest,
       TotalEnergyOverElectronNumberCalculatesCorrectlyTest)
{
    double subbandsNum = 2.0;
    double fermiWaveVector = 1.5;
    double thickness = 3.0;

    double expected = resultCalc->totalEnergy(
                          subbandsNum, fermiWaveVector, thickness) /
                      cellInfo->electronDensity();
    double result = resultCalc->totalEnergyOverElectronNumber(
        subbandsNum, fermiWaveVector, thickness);

    EXPECT_DOUBLE_EQ(result, expected);
}
