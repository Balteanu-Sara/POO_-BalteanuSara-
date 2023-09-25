#include <iostream>
#include "Circuit.h"
#include "Car.h"
#include "Weather.h"
using namespace std;

int main()
{
    Circuit c;
    c.SetLength(100);
    c.SetWeather(Weather::rain);
    c.AddCar(new Volvo());
    c.AddCar(new Bmw());
    c.AddCar(new Seat());
    c.AddCar(new Fiat());
    c.AddCar(new RangeRover());
    c.Race();
    c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the   slowest.
    c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
    return 0;
}
