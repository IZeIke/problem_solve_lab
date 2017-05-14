#include <iostream>
#include <string>
#include <stdio.h>
#include<map>
#include<vector>
using namespace std;

int main(){
    int n,x,y,r;
    cin >> n;
    int min = 100000000;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y >> r;
        if(y < 0)
        {
            y += r;
            r = 0 - y;
        }else
        {
            y -= r;
            r = y - 0;
        }

        if(r < min)
        {
            min = r;
        }
    }

    if(min <= 0)
    {
        min = -1;
    }

    cout << min << endl;
}