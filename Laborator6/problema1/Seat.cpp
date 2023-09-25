#include "Seat.h"
using namespace std;

Seat::Seat()
{
    fuelCapacity= 77;
	fuelConsumption= 19;
	averageSpeed[rain]= 30;
	averageSpeed[sunny]= 43;
	averageSpeed[snow]= 25;
}

float Seat::TFinish(bool& b, int w, int length)
{
    float time= fuelCapacity/fuelConsumption;
    int speed= averageSpeed[w];
    float distance= time*speed;
    if(distance>length) b=true;
    return (time*length/distance);
}
