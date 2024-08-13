#include "ReadData.hpp"
#include "UnitCellInfo.hpp"
#include "SampleInfo.hpp"
#include "SphereCalculation.hpp"

int main()
{
	ReadData* read = new ReadData();
	read->readUserConfig();
	read->readDb();

	SampleInfo sample(read);
	sample.setValue();
	sample.sampleArea();
	sample.sampleVolume();

	UnitCellInfo cell(read);
	cell.setValue();
	cell.cellVolume();
	cell.electronDensity();

	SphereCalculation sphere(&cell, &sample);
	sphere.calculation();
	sphere.saved();

	delete read;

	return 0;
}