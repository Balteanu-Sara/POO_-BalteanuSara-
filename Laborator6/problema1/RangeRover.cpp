#include "RangeRover.h"
using namespace std;

RangeRover::RangeRover()
{
    fuelCapacity= 71;
	fuelConsumption= 22;
	averageSpeed[rain]= 38;
	averageSpeed[sunny]= 56;
	averageSpeed[snow]= 29;
}

float RangeRover::TFinish(bool& b, int w, int length)
{
    float time= fuelCapacity/fuelConsumption;
    int speed= averageSpeed[w];
    float distance= time*speed;
    if(distance>length) b=true;
    return (time*length/distance);
}
