#include <iostream>
#include <cstring>
#include <stdarg.h>
#include <algorithm>
#include "Math.h"
using namespace std;

int Math::Add(int x , int y)
{
    return x+y;
}

int Math::Add(int x, int y, int z)
{
    return x+y+z;
}

int Math::Add(double x, double y)
{
    return x+y;
}

int Math::Add(double x, double y, double z)
{
    return x+y+z;
}

int Math::Mul(int x , int y)
{
    return x*y;
}

int Math::Mul(int x, int y, int z)
{
    return x*y*z;
}

int Math::Mul(double x, double y)
{
    return x*y;
}

int Math::Mul(double x, double y, double z)
{
    return x*y*z;
}

int Math::Add(int cont,...)
{
    int i, val,s=0;
    va_list vl;
    va_start(vl,cont);
    for(i=0; i<cont; i++)
    {
        val=va_arg(vl, int);
        s=s+val;
    }
    va_end(vl);
    return s;
}

char* Math::Add(const char* a, const char* b)
{
    if(a==nullptr || b==nullptr)
        return nullptr;
    char *s1= new char[strlen(a)], *s2= new char[strlen(b)];
    strcpy(s1,a);
    strcpy(s2,b);

    char *s3= new char[max(strlen(s1),strlen(s2))+1];
    int i,temp=0, sum=0;

    for(i=0; i<=strlen(s1)/2-1; i++)
        swap(s1[i], s1[strlen(s1)-1-i]);

    for(i=0; i<=strlen(s2)/2-1; i++)
        swap(s2[i], s2[strlen(s2)-1-i]);

    for(i=0; i<min(strlen(s1),strlen(s2)); i++)
    {
        sum=(s1[i]-'0')+(s2[i]-'0');
        if(temp!=0)
            sum=sum+temp;
        s3[i]=sum%10+'0';
        if(sum/10!=0) temp=sum/10;
    }
    for(i=min(strlen(s1),strlen(s2)); i<max(strlen(s1),strlen(s2)); i++)
    {
        if(strlen(s1)>strlen(s2))
        {
            sum=(s1[i]-'0')+0;
            if(temp!=0)
                sum=sum+temp;
            s3[i]=sum%10+'0';
            if(sum/10!=0) temp=sum/10;
        }
        else
            if(strlen(s1)<strlen(s2))
            {
                sum=(s2[i]-'0')+0;
                if(temp!=0)
                    sum=sum+temp;
                s3[i]=sum%10+'0';
                if(sum/10!=0) temp=sum/10;
            }
    }
    if(temp!=0) s3[i]=temp+'0';
    s3[i+1]=NULL;
    int j;
    for(j=0; j<=strlen(s3)/2-1; j++)
        swap(s3[j], s3[strlen(s3)-1-j]);
      delete[]s1;
      delete[]s2;
    return s3;
}
