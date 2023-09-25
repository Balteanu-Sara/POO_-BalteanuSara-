#include <iostream>
#include "Canvas.h"
using namespace std;

Canvas::Canva(int width, int height)
{
    lungime=width;
    latime= height;
    int i,j;
    mat=new char* [latime];

    for(i=0;i<latime; i++)
    {
        mat[i]=new char[lungime];
        for(j=0; j<lungime; j++)
            mat[i][j]=' ';
    }
}

Canvas::~Canvas()
{
    int i;
    for(i=0; i<latime; i++)
        delete[]mat[i];
    delete[]mat;
}

void Canvas::Clear()
{
    for(int i=0; i<latime; i++)
        for(int j=0; j<lungime; j++)
            mat[i][j]=' ';
}

void Canvas::Print()
{
    int i, j;
    for(i=0; i<latime; i++)
    {
        for(j=0; j<lungime; j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

void Canvas::SetPoint(int x, int y, char ch)
{
    mat[x][y]=ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx, dy, sx, sy, error, e2;
    dx = abs(x2 - x1);
    sx = x1 < x2 ? 1 : -1;
    dy = -abs(y2 - y1);
    sy = y1 < y2 ? 1 : -1;
    error = dx + dy;

    while (true)
    {
        mat[x1][y1]=ch;
        if(x1 == x2 && y1 == y2) break;
        e2 = 2 * error;
        if (e2 >= dy)
        {
            if (x2 == x1) break;
            error = error + dy;
            x1 = x1 + sx;
        }
        if(e2 <= dx)
        {
            if(y2 == y1) break;
            error = error + dx;
            y1 = y1 + sy;
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    DrawLine(left, top, right, top, ch);
    DrawLine(left, top, left, bottom, ch);
    DrawLine(right, top, right, bottom, ch);
    DrawLine(left, bottom, right, bottom, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    int i, j;
    for(i=top+1; i<bottom; i++)
        for(j=left+1; j<right; j++)
            mat[i][j]=ch;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    int x1 = 0, y1 = ray;
    int d = 3 - 2 * ray;
    mat[x+x1][y+y1]=ch;
    mat[x-x1][y+y1]=ch;
    mat[x+x1][y-y1]=ch;
    mat[x-x1][y-y1]=ch;
    mat[x+y1][y+x1]=ch;
    mat[x-y1][y+x1]=ch;
    mat[x+y1][y-x1]=ch;
    mat[x-y1][y-x1]=ch;
    while (y1 >= x1)
    {
        x1++;
        if (d > 0)
        {
            y1--;
            d = d + 4 * (x1 - y1) + 10;
        }
        else
            d = d + 4 * x1 + 6;
        mat[x+x1][y+y1]=ch;
        mat[x-x1][y+y1]=ch;
        mat[x+x1][y-y1]=ch;
        mat[x-x1][y-y1]=ch;
        mat[x+y1][y+x1]=ch;
        mat[x-y1][y+x1]=ch;
        mat[x+y1][y-x1]=ch;
        mat[x-y1][y-x1]=ch;
    }
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{

    for(int i=-ray; i<=ray; i++)
        for(int j=-ray; j<=ray; j++)
            if(j*j +i*i<=ray*ray)
                mat[x+j][y+i]=ch;
}
