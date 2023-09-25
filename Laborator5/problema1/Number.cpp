#include <iostream>
#include <cstring>
#include <cmath>
#include "Number.h"
using namespace std;

void Number::SwitchBase(int newBase)
{
    if(base==newBase) return;
    if(newBase==10)
    {
        strrev(v);
        int nr=0,aux,l=1,i;
        for(i=0; i<strlen(v);i++)
        {
            if(v[i]>='0' && v[i]<='9')
            {
                int cif=v[i]-'0';
                nr=nr+cif* pow(base,i);
            }
            if(v[i]>='A' && v[i]<='F')
            {
                int cif=10+(v[i]-'A');
                nr=nr+cif* pow(base,i);
            }
        }
        aux=nr;
        while(aux>=10)
        {
            aux=aux/10;
            l++;
        }
        delete[]v;
        v=new char[l+1];
        i=0;
        while(nr)
        {
            v[i]=nr%10+'0';
            i++;
            nr=nr/10;
        }
        v[i]='\0';
        base=newBase;
        return;
    }
    else
        if(base==10)
        {
            int i,nr=0,l=0;
            for(i=0; i<strlen(v); i++)
                nr=nr*10+ (v[i]-'0');
            delete[]v;
            v=new char[4*i+1];
            while(nr)
            {
                if(nr%newBase>10)
                    v[l]=nr%newBase%10 +'A';
                else
                    v[l]=nr%newBase+'0';
                l++;
                nr=nr/newBase;
            }
            v[l]='\0';
            strrev(v);
            base=newBase;
            return;
        }
    else
    {
        this->SwitchBase(10);
        this->SwitchBase(newBase);
        return;
    }
}

void Number::Print()
{
    cout<<v<<endl;
}

int Number::GetDigitsCount()
{
    int nr;
    nr=strlen(v);
    return nr;
}

int Number::GetBase()
{
    return base;
}

Number& operator+ (const Number &a1, const Number &a2)
{
    Number *n1= new Number(a1);
    Number *n2= new Number(a2);
    int b1=n1->GetBase();
    int b2=n2->GetBase();

    char *s=new char[strlen(n1->v)+strlen(n2->v)+1];
    n1->SwitchBase(10);
    n2->SwitchBase(10);

    int nr1=0, nr2=0,sum,i;
    for(i=0; i<strlen(n1->v); i++)
        nr1=nr1*10+(n1->v[i]-'0');
    for(i=0; i<strlen(n2->v); i++)
        nr2=nr2*10+(n2->v[i]-'0');
    sum=nr1+nr2;

    i=0;
    while(sum)
    {
        s[i]=sum%10+'0';
        i++;
        sum=sum/10;
    }
    s[i]='\0';
    strrev(s);

    Number *rez= new Number(s,10);
    if(b1>b2)
        rez->SwitchBase(b1);
        else rez->SwitchBase(b2);
    return *rez;

}

Number& operator- (const Number &a1,const  Number &a2)
{
    Number *n1= new Number(a1);
    Number *n2= new Number(a2);
    int b1=n1->GetBase();
    int b2=n2->GetBase();

    char *s=new char[strlen(n1->v)+strlen(n2->v)+1];
    n1->SwitchBase(10);
    n2->SwitchBase(10);


    int nr1=0, nr2=0,d,i;
    for(i=0; i<strlen(n1->v); i++)
        nr1=nr1*10+(n1->v[i]-'0');
    for(i=0; i<strlen(n2->v); i++)
        nr2=nr2*10+(n2->v[i]-'0');
    if(nr1>nr2)
        d=nr1-nr2;
    else d=nr2-nr1;

    i=0;
    while(d)
    {
        s[i]=d%10+'0';
        i++;
        d=d/10;
    }
    s[i]='\0';
    strrev(s);

    Number *rez= new Number(s,10);
    if(b1>b2)
        rez->SwitchBase(b1);
        else rez->SwitchBase(b2);
    return *rez;
}

Number& Number::operator= (const Number &n)
{
    base=n.base;
    delete[]v;
    v=new char[strlen(n.v)+1];
    memcpy(v, n.v, strlen(n.v)+1);
    return *this;
}

Number& Number::operator= (int value)
{
    char s[256];
    int l=0;
    while(value)
    {
        s[l]=value%10+'0';
        l++;
        value=value/10;
    }
    s[l]=NULL;
    strrev(s);

    Number b(s,10);
    b.SwitchBase(base);

    l=b.GetDigitsCount();

    delete[]v;
    v=new char[l+1];
    memcpy(v,b.v,l+1);
    return *this;
}

Number& Number::operator= (const char* const s)
{
    int l=strlen(s);

    delete[]v;
    v=new char[l+1];
    memcpy(v,s, l+1);
    return *this;
}

Number& operator+= (Number &n1 , const Number &n2)
{
    return n1= n1+n2;
}

Number& operator-= (Number &n1 , const Number &n2)
{
    return n1= n1-n2;
}

char Number::operator[] (int index)
{
    return *(this->v + index);
}

Number& Number::operator-- ()
{
    char *x=new char[strlen(v)];
    memcpy(x, v+1, strlen(v));
    delete[]v;
    v=new char[strlen(x)+1];
    memcpy(v,x,strlen(x)+1);
    delete[]x;
    return *this;
}

Number& Number::operator-- (int value)
{
    char *x=new char[strlen(v)];
    int i;
    for(i=0; i<strlen(v)-1; i++)
        x[i]=v[i];
    x[i]=NULL;
    delete[]v;
    v=new char[strlen(x)+1];
    memcpy(v,x,strlen(x)+1);
    delete[]x;
    return *this;
}

bool operator > (const Number &n1,const Number &n2)
{
    Number x(n1);
    Number y(n2);

    x.SwitchBase(10);
    y.SwitchBase(10);

    if(strcmp(x.v, y.v)>0) return 1;
    else return 0;
}

bool operator < (const Number &n1,const Number &n2)
{
    Number x(n1);
    Number y(n2);

    x.SwitchBase(10);
    y.SwitchBase(10);

    if(strcmp(x.v, y.v)<0) return 1;
    else return 0;
}

bool operator >= (const Number &n1,const Number &n2)
{
    return !(n1<n1);
}

bool operator <= (const Number &n1,const Number &n2)
{
    return !(n1>n1);
}
