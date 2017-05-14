#include <iostream>
#include <string>
#include <stdio.h>
#include<map>
#include<vector>
using namespace std;

int main(){
    int n,m,stage,sec;
    cin >> n >> m;
    map<int,int> video;
    for(int i=1;i<=n;i++)
    {
        video[i] = 1000;
    }
    for(int i=0;i<m;i++)
    {
        cin >> stage >> sec;
        if(sec < video[stage])
        {
            video[stage] = sec;
        }
    }
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        sum += video[i];
    }
    cout << sum << endl;
    for(int i=1;i<=n;i++)
    {
        cout << i;
        cout << " ";
        cout << video[i] << endl;
    }


}
