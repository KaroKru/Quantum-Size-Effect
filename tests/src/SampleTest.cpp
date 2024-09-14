#include "Data.hpp"
#include "ReadDataIntMock.hpp"
#include "SampleInfo.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

class SampleInfoTest : public ::testing::Test
{
  public:
    ReadDataIntMock* data;
    SampleInfo* sample;

    void SetUp() override
    {
        data = new ReadDataIntMock();
        sample = new SampleInfo(data);
    }

    void TearDown() override
    {
        delete sample;
        delete data;
    }
};

TEST_F(SampleInfoTest, CheckedThicknessTest)
{
    std::vector<ConfigData> sampleData = {{"Si", 2.5, 2.5, 2.5}};
    EXPECT_CALL(*data, getSampleValue())
        .WillOnce(::testing::Return(sampleData));

    sample->setValue();
    double thickness = sample->getSampleThickness();

    EXPECT_DOUBLE_EQ(thickness, 2.5);
}

TEST_F(SampleInfoTest, CheckedAreaTest)
{
    std::vector<ConfigData> sampleData = {{"Ni", 3.0, 3.0, 3.0}};
    EXPECT_CALL(*data, getSampleValue())
        .WillOnce(::testing::Return(sampleData));

    sample->setValue();
    double testArea = 3.0 * 3.0;
    double area = sample->sampleArea();

    EXPECT_DOUBLE_EQ(area, testArea);
}
