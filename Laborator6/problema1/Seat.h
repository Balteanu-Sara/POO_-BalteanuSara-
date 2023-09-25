#include "Car.h"

class Seat: public Car
{
public:
    Seat();
    float TFinish(bool &b, int , int ) override;
};
