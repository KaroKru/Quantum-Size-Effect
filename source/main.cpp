#include "ReadData.hpp"
#include "UnitCellInfo.hpp"
#include "SampleInfo.hpp"
#include "SphereCalculation.hpp"
#include "ResultCalculation.hpp"
#include "ElectronicDensity.hpp"
#include "ElectronicCalculation.hpp"

int main()
{
	ReadData* read = new ReadData();
	read->readUserConfig();
	read->readDb();

	SampleInfo sample(read);
	sample.setValue();
	sample.sampleArea();
	//sample.sampleVolume();

	UnitCellInfo cell(read);
	cell.setValue();
	cell.cellVolume();
	cell.electronDensity();

	ResultCalculation resultCalculation(&cell, &sample);

	SphereCalculation sphere(&sample, &resultCalculation);
	sphere.calculation();
	sphere.saved();

	ElectronicDensity density(&sample);

	ElectronicCalculation electronic(&density);
	electronic.calculation();
	electronic.saved();

	delete read;

	return 0;
}