#include <iostream>
#include <cstring>
#include "Sort.h"
using namespace std;
char c[]="40,40,1,100,34,55";
int v[5]={10, 6, 8, 22, 16};
int main()
{
    Sort s(c);
    Sort s1=s;
    Sort s2= move(s1);
    s2.BubbleSort(1);
    s2.Print();
    return 0;
}
