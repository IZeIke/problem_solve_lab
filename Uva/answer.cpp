#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cmath>  
using namespace std;

int main()
{
    int n,tcase;
    int sum = 0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> tcase;
        sum = (((((tcase*567)/9)+ 7492 )* 235)/47)-498;
        sum = abs((sum/10)%10);
        cout << sum << endl;
    }
}