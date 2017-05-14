#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cmath>  
using namespace std;

string licence(char* str)
{
    int part1 = 0;
    for(int i=2;i>=0;i--)
    {
        part1 += (*str - 65) * pow(26,i);
        str++;
    }
    str++;
    string part2 = "";
    for(int i=0;i<4;i++)
    {
        part2 = part2 + *str;
        str++;
    }
    //cout << part2 << endl; 
    int part2int = atoi( part2.c_str() );
    int sum = part1 - part2int;
    sum = abs(sum);
    if(sum <= 100)
    {
       // cout << sum << endl; 
      //  cout << part1 << endl;
       // cout << part2int << endl;
        return "nice";
    }else
    {
      //  cout << sum << endl; 
        return "not nice";
    }
}

int main()
{
    int n;
    char albert[8];
    cin >> n;
    for(int i=0;i<n;i++)
    {
        scanf("%s",albert);
        string ans = licence(albert);
        cout << ans << endl; 
    }
}