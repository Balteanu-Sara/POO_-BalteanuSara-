#include "Circuit.h"
#include "Car.h"
#include "Weather.h"
#include <iostream>
using namespace std;

Circuit::Circuit()
{
    cars=0;
    car= new Car *[10];
}

void Circuit::SetLength(int value)
{
    length=value;
}

void Circuit::SetWeather(int w)
{
    weather=w;
}

void Circuit::AddCar(Car* c)
{
    car[cars]=c;
    cars++;
}

void Circuit::Race()
{
    int i;
    for(i=0; i<cars; i++)
    {
        bool b=false;
        timeFinish[i]=car[i]->TFinish(b, weather, length);
        finish[i]=b;
    }
}

void Circuit::ShowFinalRanks()
{
    int i,j;
    float aux;
    for(i=0; i<cars-1; i++)
        for(j=i+1; j<cars; j++)
            if(timeFinish[i]>timeFinish[j])
            {
                aux=timeFinish[i];
                timeFinish[i]=timeFinish[j];
                timeFinish[j]=aux;

                Car *m=car[i];
                car[i]=car[j];
                car[j]=m;

                bool auxx;
                auxx=finish[i];
                finish[i]=finish[j];
                finish[j]=auxx;
            }
    cout<<"Timpul masinilor care au terminat cursa:"<<endl;
    for(i=0; i<cars; i++)
        if(finish[i]==true)
            cout<<timeFinish[i]<<endl;
    cout<<endl;
}

void Circuit::ShowWhoDidNotFinish()
{
    int i;
    cout<<"Timpul masinilor care nu au terminat cursa:"<<endl;
    for(i=0; i<cars; i++)
    {
        if(finish[i]==false)
            cout<<timeFinish[i]<<endl;
    }
}
