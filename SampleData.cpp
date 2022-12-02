#define _USE_MATH_DEFINE
#include "SampleData.h"

SampleData::SampleData(double& p_xLength, double& p_yLength, std::string& p_elementType, double& p_thicknessOfSample)
{
	std::cout << "SampleData constructor" << std::endl;
	xLength = p_xLength;
	yLength = p_yLength;
	elementType = p_elementType;
	thicknessOfSample = p_thicknessOfSample;
}

SampleData::~SampleData()
{
	std::cout << "SampleData destructor" << std::endl;
}

double SampleData::sampleArea(double& xLength, double& yLength)
{
	return xLength * yLength;
}

double SampleData::sampleVolume(double& xLength, double& yLength, double& thicknessOfSample)
{
	return sampleArea(xLength, yLength) * sampleThickness(thicknessOfSample);
}

int SampleData::electronDensityValue(std::string& elementType)
{
	int electronDensity{ 0 };

	if (elementType == "Pb")
	{
		electronDensity = 132;
	}
	else if (elementType == "Al")
	{
		electronDensity = 180;
	}
	else
	{
		std::cout << "provide the value of the electron density ";
		std::cin >> electronDensity;
	}

	return electronDensity;
}

double SampleData::sampleThickness(double& thicknessOfSample)
{
	return thicknessOfSample;
}

double SampleData::deltaKz(double& thicknessOfSample)
{
	return M_PI / sampleThickness(thicknessOfSample);
}

double SampleData::sum(double& numberOfSubbands)
{
	return (numberOfSubbands * (numberOfSubbands + 1) * (2 * numberOfSubbands + 1)) / 6;
}

double SampleData::fermiSphere(double& numberOfSubbands, double& thicknessOfSample, std::string& elementType)
{
	return sqrt((1 / numberOfSubbands) * (2 * M_PI * sampleThickness(thicknessOfSample) * electronDensityValue(elementType) + sum(numberOfSubbands) * pow(M_PI, 2)));
}

double SampleData::DOSFermi(double electronMass, double& planckReducee, double& thicknessOfSample, double& numberOfSubbands)
{
	return (electronMass * numberOfSubbands) / (M_PI * pow(planckReducee, 2) * sampleThickness(thicknessOfSample));
}

double SampleData::numberOfElectrons(std::string& elementType, double& xLength, double& yLength, double& thicknessOfSample)
{
	return electronDensityValue(elementType) * sampleVolume(xLength, yLength, thicknessOfSample);
}

double SampleData::sum2(double& numberOfSubbands)
{
	return ((numberOfSubbands * (numberOfSubbands + 1) * (2 * numberOfSubbands + 1) * (3 * pow(numberOfSubbands, 2) + 3 * numberOfSubbands - 1)) / 30);
}

double SampleData::totalEnergy(double& electronMass, double& planckReducee, double& thicknessOfSample, double& numberOfSubbands, std::string& elementType)
{
	return ((pow(planckReducee, 2)) / (8 * M_PI * electronMass * sampleThickness(thicknessOfSample))) * (numberOfSubbands * pow(fermiSphere(numberOfSubbands, thicknessOfSample, elementType), 4) - sum2(numberOfSubbands) * pow(M_PI * sampleThickness(thicknessOfSample), 4));
}

double SampleData::totalEnergyOverElectronNumber(std::string& elementType, double& xLength, double& yLength, double& thicknessOfSample, double& electronMass, double& planckReducee, double& numberOfSubbands)
{
	return totalEnergy(electronMass, planckReducee, thicknessOfSample, numberOfSubbands, elementType) / numberOfElectrons(elementType, xLength, yLength, thicknessOfSample);
}