#include <iostream>
#include "Math.h"
using namespace std;

int main()
{
    Math m;
    cout<<m.Add(5, 'a')<<'\n';
    cout<<m.Add(true, 12, 10)<<'\n';
    cout<<m.Add(5.2, 1.1)<<'\n';
    cout<<m.Add(34.2, 5.0f, 2.1)<<'\n';

    cout<<m.Mul('b', true)<<'\n';
    cout<<m.Mul(3, 'a', false)<<'\n';
    cout<<m.Mul(34.7f, 2.5)<<'\n';
    cout<<m.Mul(3.14f, 3.0, 5.6f)<<'\n';

    cout<<m.Add(3, 15, 'a', true)<<'\n';
    const char* x="99";
    const char* y="98";
    cout<<m.Add(x,y);
    return 0;
}
