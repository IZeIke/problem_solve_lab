#include <iostream>
#include <string>
#include <stdio.h>
#include<map>
#include<vector>
using namespace std;

int main(){
    map<int,char> set;
    char str;
    int i=0;
    int ans = 0;
    while(true)
    {
        cin >> str;
        set[i] = str;
        if(str == '}')
        {
            if(i == 1)
            {
                ans = 0;
            }else
            {
                ans++;
            }
            break;
        }else
        if(str == ',')
        {
            ans++;
        }
        i++;
    }
    int sum = 1;
    for(int i=0;i<ans;i++)
    {
        sum = sum * 2;
    }
    cout << sum << endl;
}