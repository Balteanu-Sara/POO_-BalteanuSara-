#include "Car.h"

class Bmw: public Car
{
public:
    Bmw();
    float TFinish(bool &b, int , int CircuitLength) override;
};
