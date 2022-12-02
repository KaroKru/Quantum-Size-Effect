#pragma once
#include <iostream>
#include <cmath>

class ConstData
{
public:
	double speedOfLigth = 299792458 * (pow(10, 9));
	double mass = (511000) / (pow(speedOfLigth, 2));
	double planckReduceeValue = 6.58 * (pow(10, -16));

public:
	ConstData();
	~ConstData();
};