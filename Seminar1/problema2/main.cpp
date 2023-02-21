#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int main()
{
    char s[256], *p, cuv[256][256];
    int n=0, i, j;
    scanf("%[^\n]s", s);
    p=strtok(s," ");
    while(p)
    {
        strcpy(cuv[n],p);
        n++;
        p=strtok(NULL," ");
    }
    n--;
    for(i=0; i<n; i++)
        for(j=i+1; j<=n; j++)
        {
            if(strlen(cuv[i])<strlen(cuv[j]))
                swap(cuv[i], cuv[j]);
            else if(strlen(cuv[i])==strlen(cuv[j]))
            {
                if(strcmp(cuv[i], cuv[j])>0)
                    swap(cuv[i], cuv[j]);
            }

        }
    for(i=0;i<=n; i++)
    {
        printf("%s\n", cuv[i]);
    }
    return 0;
}
