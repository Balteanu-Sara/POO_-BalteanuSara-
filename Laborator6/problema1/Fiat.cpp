#include "Fiat.h"
using namespace std;

Fiat::Fiat()
{
    fuelCapacity= 80;
	fuelConsumption= 20;
	averageSpeed[rain]= 40;
	averageSpeed[sunny]= 47;
	averageSpeed[snow]= 30;
}

float Fiat::TFinish(bool& b, int w, int length)
{
    float time= fuelCapacity/fuelConsumption;
    int speed= averageSpeed[w];
    float distance= time*speed;
    if(distance>length) b=true;
    return (time*length/distance);
}
