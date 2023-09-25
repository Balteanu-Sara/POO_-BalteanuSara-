#include <iostream>

using namespace std;

float operator"" _Kevin(const char *a)
{
    float value=0;

    while((*a)!=0)
    {
        value= value*10+ (*a)-'0';
        a++;
    }
    value=value-273.15;
    return value;
}

float operator"" _Fahrenheit(const char *b)
{
    float value=0;

    while((*b)!=0)
    {
        value= value*10+ (*b)-'0';
        b++;
    }
    value= (value-32.0)/1.8;
    return value;
}

int main()
{
    float a=300_Kevin;
    float b=120_Fahrenheit;
    cout<<a<< " "<<b;
    //cout<<(int)'\0';
    return 0;
}
