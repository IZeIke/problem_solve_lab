#include <iostream>
#include <string>
#include <stdio.h>
#include<map>
using namespace std;

int main()
{
    int n,expert;
    int win1,win2,win3,win4;
    int a,b,winner,winrun,wina,winb;
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    int max4 = 0;
    cin >> n;

    for(int i=1;i<=4*n;i++)
    {
        cin >> expert;
        if(i <= n)
        {
            if(expert > max1)
            {
                max1 = expert;
                win1 = i;
            }
        }else if(i <= 2*n)
        {
            if(expert > max2)
            {
                max2 = expert;
                win2 = i;
            }
        }else if(i <= 3*n)
        {
            if(expert > max3)
            {
                max3 = expert;
                win3 = i;
            }
        }else if(i <= 4*n)
        {
            if(expert > max4)
            {
                max4 = expert;
                win4 = i;
            }
        }
    }
    int maxa,maxb;
    if(max1 > max2)
    {
        a = win2;
        wina = win1;
        maxa = max1;
    }else
    {
        a = win1;
        wina = win2;
        maxa = max2;
    }
    if(max3 > max4)
    {
        b = win4;
        winb = win3;
        maxb = max3;
    }else
    {
        b = win3;
        winb = win4;
        maxb = max4;
    }
    if(maxa > maxb)
    {
        winner = wina;
        winrun = winb;
    }else
    {
        winner = winb;
        winrun = wina;
    }
    printf("%d %d %d %d \n",winner,winrun,a,b); 
}