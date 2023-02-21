#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int convert(char v[])
{
    int i=0,a=0;
    while (v[i]>='0' && v[i]<='9')
    {
        a=a*10+(v[i]-'0');
        i++;
    }
    return a;
}
int main()
{
    FILE* p;
    p=fopen("in1.txt", "r");
    char x[50];
    int n=0, s=0;
    if(p==NULL)
    {
        printf("Fisierul nu exista.");
    }
    else
    {
        while (fgets(x,50,p)!=NULL)
        {
            s=s+convert(x);

        }
        printf("%d", s);
    }
    fclose(p);
    return 0;
}
