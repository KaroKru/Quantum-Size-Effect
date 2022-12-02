#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "ConstData.h"
#include "SampleData.h"

void aboutCode()
{
	std::cout << "Code for Quantum Size Effect (QSE) calculation\n";
	std::cout << "Based on the article: W. A. Atkinson, A.J. Salvin\n ";
	std::cout << "A free-electron calculation for quantum size effects in the properties of metallic islands on surfaces\n";
	std::cout << "American Journal of Physics 76 (12) 2008" << std::endl;
	std::cout << "________________________________________________________________________________________________" << std::endl;
	std::cout << "Prefered samples: \n";
	std::cout << "- Lead (Pb), electron density 132 nm^-3" << std::endl;
	std::cout << "- Aluminium (Al), electron density 180 nm^-3" << std::endl;
}

int main()
{
	aboutCode();
	std::fstream file;
	file.open("QSE.txt", std::ios::out);

	std::string element;
	double aLength{ 0 };
	double bLength{ 0 };
	double thickness{ 0 };

	SampleData sample(aLength, bLength, element, thickness);

	std::cout << "Enter the type of element, as Pb or Al " << std::endl;
	std::cin >> element;
	sample.electronDensityValue(element);
	std::cout << "Electron density: " << sample.electronDensityValue(element) << std::endl;

	std::cout << "Enter the a and b length of sample in nm" << std::endl;
	std::cin >> aLength >> bLength;
	sample.sampleArea(aLength, bLength);
	std::cout << "Sample area: " << sample.sampleArea(aLength, bLength) << std::endl;

	std::cout << "In calculation of QSE the sample should has the thickness between 0.3 and 3 nm" << std::endl;
	std::cout << "provide the thickness of sample in nm: ";
	std::cin >> thickness;

	if (thickness < 0.3 or thickness > 3.0)
	{
		std::cout << "wrong value of sample thickness " << std::endl;
		std::cout << "provide once againt sample thickness ";
		std::cin >> thickness;
	}
	else
	{
		std::cout << "Sample thickness: " << sample.sampleThickness(thickness) << std::endl;
		sample.sampleVolume(aLength, bLength, thickness);
		std::cout << "Sample volume: " << sample.sampleVolume(aLength, bLength, thickness) << std::endl;
	}

	int calculationStep{ 0 };
	std::cout << "Choose how many times do you want to calculate (as 10 or 1000)";
	std::cin >> calculationStep;

	std::cout << "Choose the step of changes the sample thickness (as 10 or 1000), which will be calculate as 1/step: ";
	double step{ 0 };
	std::cin >> step;

	double P = 0;
	double p = 1;

	std::vector<double> subbands;
	std::vector<double> sampThickness;
	std::vector<double> fermSphere;
	std::vector<double> dos;
	std::vector<double> totEnergy;

	try
	{

		if (!file)
		{
			std::cout << "Problem with creation of a file " << std::endl;
			throw 0;
		}
		else
		{

			for (int it = 1; it < calculationStep; it++)
			{
				P = sample.fermiSphere(p, thickness, element) / sample.deltaKz(thickness);

				if (p < static_cast<int>(P))
				{
					p += 1;
				}

				std::cout << it << " " << p << " " << sample.sampleThickness(thickness) << " " << sample.fermiSphere(p, thickness, element)
					<< " " << sample.DOSFermi(sample.mass, sample.planckReduceeValue, thickness, p) << " " << sample.totalEnergyOverElectronNumber(element, aLength, aLength, thickness, sample.mass, sample.planckReduceeValue, p) << std::endl;

				subbands.push_back(p);
				sampThickness.push_back(sample.sampleThickness(thickness));
				fermSphere.push_back(sample.fermiSphere(p, thickness, element));
				dos.push_back(sample.DOSFermi(sample.mass, sample.planckReduceeValue, thickness, p));
				totEnergy.push_back(sample.totalEnergyOverElectronNumber(element, aLength, aLength, thickness, sample.mass, sample.planckReduceeValue, p));


				file << subbands[it-1] << " " <<
					sampThickness[it-1] << " " <<
					fermSphere[it-1] << " " <<
					dos[it-1] << " " <<
					totEnergy[it-1] << " " << std::endl;

				thickness += (1 / step);
			}
		}
	}
	catch (...)
	{
		std::cout << "problem with calculation and saving data" << std::endl;
	}

	file.close();

	return 0;
}
