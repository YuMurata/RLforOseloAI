#pragma once
#include"stdafx.h"

#include<Coordinate.h>

typedef TCoordinate<double> Rate;

class RateClass
{
public:
	Rate rate;

	RateClass() :rate(Rate(1, 1)) {}

	void SetRate(const Rate &obj=Rate(1,1))
	{
		this->rate = obj;
	}

	Rate GetRate()const
	{
		return this->rate;
	}
};