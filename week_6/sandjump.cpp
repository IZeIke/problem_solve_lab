#include <iostream>
#include <string>
#include <stdio.h>
#include<map>
#include<vector>
using namespace std;

int main(){
    int r,s,t;
    int n;
    int dis;
    int sum = 0;
    int pos;
    cin >> r >> s >> t;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> dis;
        sum += r;
        pos = 1;
        while(true)
        {
            if(sum >= dis)
            {
                break;
            }else
            if(pos == 1)
            {
                sum += s;
                pos = 2;
            }else
            if(pos == 2)
            {
                sum += t;
                if(sum == dis)
                {
                    pos = 2;
                }else
                {
                    pos = 1;
                }      
            }
        }
        sum = 0;
        if(pos == 2)
        {
            cout << "yes" << endl;
        }else
        {
            cout << "no" << endl;
        }
    }
}