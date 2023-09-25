#include "Car.h"

class RangeRover: public Car
{
public:
    RangeRover();
    float TFinish(bool &b, int , int ) override;
};
