#include "Data.hpp"
#include "ElectronicCalculation.hpp"
#include "ElectronicDensity.hpp"
#include "ReadDataIntMock.hpp"
#include "SampleInfo.hpp"
#include <fstream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

class ElectronicCalcTest : public ::testing::Test
{
  protected:
    std::unique_ptr<ReadDataIntMock> data;
    SampleInfo* sample;
    ElectronicDensity* density;
    std::unique_ptr<ElectronicCalculation> electronicCalc;

    void SetUp() override
    {
        data = std::make_unique<ReadDataIntMock>();

        std::vector<ElementData> elementData = {
            {"Si", 14, "FCC", 5.43, 5.43, 5.43, 4}};
        std::vector<ConfigData> sampleData = {{"Si", 2.0, 2.0, 2.0}};

        ON_CALL(*data, getCellValue())
            .WillByDefault(::testing::Return(elementData));
        ON_CALL(*data, getSampleValue())
            .WillByDefault(::testing::Return(sampleData));

        sample = new SampleInfo(data.get());
        sample->setValue();

        density = new ElectronicDensity(sample);
        electronicCalc = std::make_unique<ElectronicCalculation>(
            std::move(std::make_unique<ElectronicDensity>(*density)));
    }

    void TearDown() override {}
};

TEST_F(ElectronicCalcTest, CalculationTest)
{
    electronicCalc->calculation();

    ASSERT_FALSE(electronicCalc->electronicInfo.empty());

    EXPECT_GT(electronicCalc->electronicInfo[0].density, 0);
    EXPECT_GE(electronicCalc->electronicInfo[0].energy, 0);
}

TEST_F(ElectronicCalcTest, SavedTest)
{
    ElectronicData data;
    data.density = 10.0;
    data.energy = 0.1;
    electronicCalc->electronicInfo.push_back(data);

    ASSERT_NO_THROW(electronicCalc->saved());

    std::ifstream file("electronicData.txt");
    ASSERT_TRUE(file.is_open());

    std::string line;
    std::getline(file, line);
    EXPECT_EQ(line, "10,0.1");

    file.close();
}
