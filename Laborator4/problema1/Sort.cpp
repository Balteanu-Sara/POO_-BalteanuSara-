#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <stdarg.h>
#include "Sort.h"

using namespace std;

Sort::Sort(int cont, int x, int y): n(cont)
{
    a=new int[cont];
    srand (time(NULL));
    int i;
    for(i=0; i<cont; i++)
        a[i]=rand()%(y-x+1)+x;
}

Sort::Sort(): n(5)
{
    a=new int[n];
    a[0]=10;
    a[1]=6;
    a[2]=8;
    a[3]=17;
    a[4]=15;
}

Sort::Sort(int cont, int v[]): n(cont)
{
    a=new int[cont];
    int i;
    for(i=0; i<cont; i++)
        a[i]=v[i];
}

Sort::Sort(int cont,...): n(cont)
{
    a=new int[cont];
    int i, val;
    va_list vl;
    va_start(vl,cont);
    for(i=0; i<cont; i++)
    {
        val=va_arg(vl, int);
        a[i]=val;
    }
    va_end(vl);
}

Sort::Sort(char c[])
{
    int l=0;
    l=strlen(c);
    a=new int[l];
    char *p;
    int cont=0,i;
    p=strtok(c,",");
    while(p)
    {
        int nr=0;
        for(i=0; i<strlen(p); i++)
           nr=nr*10+(p[i]-'0');
        a[cont]=nr;
        cont++;
        p=strtok(NULL,",");
    }
    n=cont;
}

void Sort::InsertSort(bool ascendent)
{
    int i, j, aux;
    if(ascendent)
    {
        for(i=1; i<n; i++)
        {
            j=i;
            while(j>0 && a[j-1]>a[j])
            {
                aux=a[j-1];
                a[j-1]=a[j];
                a[j]=aux;
                j--;
            }
        }
    }
    else{
        for(i=1; i<n; i++)
        {
            j=i;
            while(j>0 && a[j-1]<a[j])
            {
                aux=a[j-1];
                a[j-1]=a[j];
                a[j]=aux;
                j--;
            }
        }
    }
}

void Sort::QuickSort(bool ascendent)
{
    quickSort(0,n-1,ascendent);
}

void Sort::quickSort(int p, int q, bool ascendent)
{
    int k;
    if(p<q)
    {
        partitioneaza(p,q,k,ascendent);
        quickSort(p,k-1,ascendent);
        quickSort(k+1,q,ascendent);
    }
}

void Sort::partitioneaza(int p, int q, int &k, bool ascendent)
{
    int x,i,j;
    x=a[p];
    i=p+1;
    j=q;
    if(ascendent==true)
    {
        while(i<=j)
        {
            if(a[i]<=x)
                i=i+1;
            if(a[j]>=x)
                j--;
            if (i<j && a[i]>x && x>a[j])
            {
                swap(a[i],a[j]);
                i=i+1;
                j=j-1;
            }
        }
    }
    else if(ascendent==false)
    {
        while(i<=j)
        {
            if(a[i]>=x)
                i=i+1;
            if(a[j]<=x)
                j--;
            if (i<j && a[i]<x && x<a[j])
            {
                swap(a[i],a[j]);
                i=i+1;
                j=j-1;
            }
        }
    }
    k=i-1;
    a[p]=a[k];
    a[k]=x;
}

void Sort::BubbleSort(bool ascendent)
{
    int i, j, aux;
    if(ascendent)
    {
        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
                if(a[i]>a[j])
                {
                    aux=a[i];
                    a[i]=a[j];
                    a[j]=aux;
                }
    }
    else{
        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
                if(a[i]<a[j])
                {
                    aux=a[i];
                    a[i]=a[j];
                    a[j]=aux;
                }
    }
}

void Sort::Print()
{
    int i;
    for(i=0; i<n; i++)
        cout<<a[i]<<" ";
}

int Sort::GetElementsCount()
{
    return n;
}

int Sort::GetElementFromIndex(int index)
{
    return a[index];
}
