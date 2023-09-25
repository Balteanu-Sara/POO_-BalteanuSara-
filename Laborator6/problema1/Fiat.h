#include "Car.h"

class Fiat: public Car
{
public:
    Fiat();
    float TFinish(bool &b, int , int ) override;
};
