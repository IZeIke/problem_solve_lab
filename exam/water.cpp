#include <iostream>
#include <string>
#include <stdio.h>
#include<vector>
using namespace std;

int main()
{
    int n,waterlevel;
    int sum = 0;
    int level[10000];
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> waterlevel;
        level[i] = waterlevel;
        if(i == 0)
        {
            continue;
        }

        if(level[i-1] - level[i] > 10)
        {
            int temp = level[i-1] - level[i];

            if(temp > 70)
            {
                temp = 70;
            }

            temp *= 10;

            sum += temp;
        }
    }
    cout << sum << endl; 
}