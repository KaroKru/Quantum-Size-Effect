#include "CalculationIntMock.hpp"
#include "Data.hpp"
#include "ReadDataIntMock.hpp"
#include "ResultCalculation.hpp"
#include "SampleInfo.hpp"
#include "SphereCalculation.hpp"
#include "UnitCellInfo.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class SphereCalcTest : public ::testing::Test
{
  public:
    ReadDataIntMock* data;
    SampleInfo* sample;
    UnitCellInfo* cellInfo;
    ResultCalculation* result;
    CalculationIntMock* mockCalc;
    SphereCalculation* sphere;

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

        result = new ResultCalculation(cellInfo, sample);
        mockCalc = new CalculationIntMock();
        sphere = new SphereCalculation(sample, result);
    }

    void TearDown()
    {
        delete sphere;
        delete mockCalc;
        delete result;
        delete cellInfo;
        delete sample;
        delete data;
    }
};

TEST_F(SphereCalcTest, CalculationTest)
{
    EXPECT_CALL(*mockCalc, calculation()).Times(1);

    mockCalc->calculation();
}

TEST_F(SphereCalcTest, SavedTest)
{
    EXPECT_CALL(*mockCalc, saved()).Times(1);

    mockCalc->saved();
}
