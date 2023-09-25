#include "Car.h"
#include "Bmw.h"
#include "Volvo.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"

class Circuit
{
    int length;
    int cars;
    int weather;
    Car** car;
    float timeFinish[10];
    bool finish[10];

public:
    Circuit();
    ~Circuit()
    {
        for(int i=0; i<cars; i++)
            delete car[i];
    }
    void SetLength(int value);
    void SetWeather(int w);
    void AddCar(Car* c);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};
