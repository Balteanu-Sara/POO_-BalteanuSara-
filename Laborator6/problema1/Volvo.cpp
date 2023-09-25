#include "Volvo.h"
using namespace std;

Volvo::Volvo()
{
    fuelCapacity= 60;
	fuelConsumption= 12;
	averageSpeed[rain]= 35;
	averageSpeed[sunny]= 48;
	averageSpeed[snow]= 23;
}

float Volvo::TFinish(bool& b, int w, int length)
{
    float time= fuelCapacity/fuelConsumption;
    int speed= averageSpeed[w];
    float distance= time*speed;
    if(distance>length) b=true;
    return (time*length/distance);
}
