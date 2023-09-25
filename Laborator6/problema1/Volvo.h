#include "Car.h"

class Volvo: public Car
{
public:
    Volvo();
    float TFinish(bool &b, int , int ) override;
};
