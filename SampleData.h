#pragma once
#define _USE_MATH_DEFINES
#include <string>
#include <iostream>
#include "ConstData.h"

class SampleData : public ConstData
{
private:
	double xLength;
	double yLength;
	std::string elementType;
	double thicknessOfSample;

public:
	SampleData(double& p_xLength, double& p_yLength, std::string &p_elementType, double &p_thicknessOfSample);
	~SampleData();

	double sampleArea(double& xLength, double& yLength);
	double sampleVolume(double& xLength, double& yLength, double& thicknessOfSample);
	int electronDensityValue(std::string& elementType);
	double sampleThickness(double& thicknessOfSample);
	double deltaKz(double& thicknessOfSample);
	double sum(double& numberOfSubbands);
	double fermiSphere(double& numberOfSubbands, double& thicknessOfSample, std::string& elementType);
	double DOSFermi(double electronMass, double& planckReducee, double& thicknessOfSample, double& numberOfSubbands);
	double numberOfElectrons(std::string& elementType, double& xLength, double& yLength, double& thicknessOfSample);
	double sum2(double& numberOfSubbands);
	double totalEnergy(double& electronMass, double& planckReducee, double& thicknessOfSample, double& numberOfSubbands, std::string& elementType);
	double totalEnergyOverElectronNumber(std::string& elementType, double& xLength, double& yLength, double& thicknessOfSample, double& electronMass, double& planckReducee, double& numberOfSubbands);
};