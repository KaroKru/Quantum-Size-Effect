#include "CalculationIntMock.hpp"
#include "Data.hpp"
#include "ReadDataIntMock.hpp"
#include "ResultCalculation.hpp"
#include "SampleInfo.hpp"
#include "SphereCalculation.hpp"
#include "UnitCellInfo.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

class SphereCalcTest : public ::testing::Test
{
  public:
    std::unique_ptr<ReadDataIntMock> data;
    SampleInfo* sample;
    UnitCellInfo* cellInfo;
    ResultCalculation* result;
    CalculationIntMock* mockCalc;
    SphereCalculation* sphere;

    void SetUp() override
    {
        data = std::make_unique<ReadDataIntMock>();
        std::vector<ElementData> elementData = {
            {"Si", 14, "FCC", 5.43, 5.43, 5.43, 4}};
        std::vector<ConfigData> sampleData = {{"Si", 2.5, 2.5, 2.5}};

        EXPECT_CALL(*data, getCellValue())
            .WillOnce(::testing::Return(elementData));
        EXPECT_CALL(*data, getSampleValue())
            .WillOnce(::testing::Return(sampleData));

        cellInfo = new UnitCellInfo(data.get());
        cellInfo->setValue();

        sample = new SampleInfo(data.get());
        sample->setValue();

        result = new ResultCalculation(cellInfo, sample);
        mockCalc = new CalculationIntMock();
        sphere = new SphereCalculation(sample, result);
    }

    void TearDown() override
    {
        delete sphere;
        delete mockCalc;
        delete result;
        delete cellInfo;
        delete sample;
    }
};

TEST_F(SphereCalcTest, CalculationTest)
{
    sphere->calculation();
    ASSERT_FALSE(sphere->data.empty());

    for (const auto& sampleData : sphere->data)
    {
        EXPECT_GT(sampleData.samThickness, 0);
        EXPECT_GT(sampleData.samWaveVec, 0);
        EXPECT_GT(sampleData.samNumOfSubbands, 0);
        EXPECT_GT(sampleData.samStatestDensity, 0);
        EXPECT_TRUE(std::isnan(sampleData.samElectEnergy) || sampleData.samElectEnergy >= 0);
    }
}

TEST_F(SphereCalcTest, SavedTest)
{
    sphere->calculation();

    sphere->saved();

    std::ifstream inFile("savedData.txt");
    ASSERT_TRUE(inFile.is_open());

    std::stringstream buffer;
    buffer << inFile.rdbuf();
    std::string content = buffer.str();

    ASSERT_FALSE(content.empty());

    std::istringstream ss(content);
    std::string line;

    while (std::getline(ss, line))
    {
        std::istringstream lineStream(line);
        double thickness, waveVec, numOfSubbands, statestDensity, electEnergy;
        char comma;

        lineStream >> thickness >> comma >> waveVec >> comma >> numOfSubbands >> comma >> statestDensity >> comma >> electEnergy;

        EXPECT_GT(thickness, 0);
        EXPECT_GT(waveVec, 0);
        EXPECT_GT(numOfSubbands, 0);
        EXPECT_GT(statestDensity, 0);
        EXPECT_TRUE(std::isnan(electEnergy) || electEnergy >= 0);
    }

    inFile.close();

    remove("savedData.txt");
}
