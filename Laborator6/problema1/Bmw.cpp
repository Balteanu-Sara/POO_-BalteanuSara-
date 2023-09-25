#include "Bmw.h"
using namespace std;

Bmw::Bmw()
{
    fuelCapacity= 70;
	fuelConsumption= 21;
	averageSpeed[rain]= 25;
	averageSpeed[sunny]= 50;
	averageSpeed[snow]= 15;
}

float Bmw::TFinish(bool& b, int w, int length)
{
    float time= fuelCapacity/fuelConsumption;
    int speed= averageSpeed[w];
    float distance= time*speed;
    if(distance>length) b=true;
    return (time*length/distance);
}

