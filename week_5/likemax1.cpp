#include <map>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,like;
    int max = 0;
    int maxpos;
    scanf("%d", &n);
    map<int,int> status,statusR;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &like);
        status[like]++;
        if(status[like] > max)
        {
            max = status[like];
            maxpos = like;
        }else
        if(status[like] == max)
        {
            maxpos = like;
        }
        
        printf("%d \n",maxpos); 
    }
}