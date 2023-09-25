#include "Weather.h"
#pragma once

class Car
{
protected:
    int fuelCapacity;
	int fuelConsumption;
	int averageSpeed[3];
public:
    virtual float TFinish(bool &, int , int ) =0;

    virtual ~Car() {}
};
