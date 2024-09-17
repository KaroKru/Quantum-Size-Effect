#include "ElectronicCalculation.hpp"
#include "ElectronicDensity.hpp"
#include "ReadData.hpp"
#include "ReadDataInt.hpp"
#include "ResultCalculation.hpp"
#include "SampleInfo.hpp"
#include "SphereCalculation.hpp"
#include "UnitCellInfo.hpp"
#include "CalculationInt.hpp"
#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<ReadDataInt> read = std::make_unique<ReadData>();
    read->readUserConfig();
    read->readCellValues();

    auto sample = std::make_unique<SampleInfo>(read.get());
    sample->setValue();
    sample->sampleArea();

    auto cell = std::make_unique<UnitCellInfo>(read.get());
    cell->setValue();
    cell->cellVolume();
    cell->electronDensity();

    ResultCalculation resultCalculation(cell.get(), sample.get());

    std::unique_ptr<CalculationInt> calc;
    calc = std::make_unique<SphereCalculation>(sample.get(), &resultCalculation);
    calc->calculation();
    calc->saved();

    auto density = std::make_unique<ElectronicDensity>(sample.get());

    calc = std::make_unique<ElectronicCalculation>(std::move(density));
    calc->calculation();
    calc->saved();

    return 0;
}