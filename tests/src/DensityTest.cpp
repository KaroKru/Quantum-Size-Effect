#include "Data.hpp"
#include "ElectronicDensity.hpp"
#include "ReadDataIntMock.hpp"
#include "SampleInfo.hpp"
#include <cmath>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

class DensityTest : public ::testing::Test
{
  protected:
    ReadDataIntMock* data;
    SampleInfo* sample;
    ElectronicDensity* density;

    void SetUp() override
    {
        data = new ReadDataIntMock();

        std::vector<ElementData> elementData = {
            {"Si", 14, "FCC", 5.43, 5.43, 5.43, 4}};
        std::vector<ConfigData> sampleData = {{"Si", 2.0, 2.0, 2.0}};

        EXPECT_CALL(*data, getSampleValue())
            .WillOnce(::testing::Return(sampleData));

        sample = new SampleInfo(data);
        sample->setValue();
        density = new ElectronicDensity(sample);
        ASSERT_TRUE(sample->getSampleThickness() > 0);
    }

    void TearDown() override
    {
        delete density;
        delete sample;
        delete data;
    }
};

TEST_F(DensityTest, FermiValueTest)
{
    double energy = 1.0;
    double expectedFermiValue =
        sqrt((2 * MASS * energy) / (pow(PLANCK_VALUE, 2)));
    double actualFermiValue = density->fermiValue(energy);

    EXPECT_NEAR(actualFermiValue, expectedFermiValue, 1e-9);
}

TEST_F(DensityTest, DensityOfStatesTest)
{
    double energy = 1.0;
    double numOfSubbands = 2.0;
    double thickness = sample->getSampleThickness();
    double expectedDensityOfStates =
        (MASS / (M_PI * (pow(PLANCK_VALUE, 2)) * thickness)) *
        numOfSubbands;
    double actualDensityOfStates =
        density->densityOfStates(energy, numOfSubbands);

    EXPECT_NEAR(actualDensityOfStates, expectedDensityOfStates, 1e-9);
}

TEST_F(DensityTest, DeltaZWaveVectorTest)
{
    double thickness = sample->getSampleThickness();
    double expectedDeltaZWaveVector = M_PI / thickness;
    double actualDeltaZWaveVector = density->deltaZWaveVector();

    EXPECT_NEAR(actualDeltaZWaveVector, expectedDeltaZWaveVector,
                1e-9);
}
