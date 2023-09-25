#include <iostream>
#include "Canvas.h"
using namespace std;

int main()
{
    Canvas c;
    c.Canva(80, 80);
    c.~Canvas();
    c.Clear();

    c.DrawLine(10, 10, 60, 10, 'O');

    c.DrawRect(20, 20, 30, 30, 'O');
    c.FillRect(20, 20, 30, 30, 'O');

    c.DrawCircle(60, 60, 10, '#');
    c.FillCircle(60, 60, 10, '#');
    c.Print();
    return 0;
}
