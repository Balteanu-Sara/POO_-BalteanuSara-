#include "Car.h"

class Seat: public Car
{
    double getFuelCapacity();
    double getFuelConsumption();
    double getAverageSpeed(Weather w);
};
