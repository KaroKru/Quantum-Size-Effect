#include "ReadData.hpp"
#include "UnitCellInfo.hpp"
#include "SampleInfo.hpp"
#include "SphereCalculation.hpp"
#include "ResultCalculation.hpp"
#include "ElectronicDensity.hpp"
#include "ElectronicCalculation.hpp"
#include <iostream>
#include <memory>

int main()
{
	auto read = std::make_unique<ReadData>();
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

	SphereCalculation sphere(sample.get(), &resultCalculation);
	sphere.calculation();
	sphere.saved();

	auto density = std::make_unique<ElectronicDensity>(sample.get());

	ElectronicCalculation electronic(std::move(density));
	electronic.calculation();
	electronic.saved();

	return 0;
}