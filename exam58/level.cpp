#include <iostream>
#include <string>
#include <stdio.h>
#include<map>
using namespace std;

int main()
{
    int n,m,a,b,c,x,y,z;
    int exper = 0;
    int level = 1;
    int statx=0;
    int staty =0;
    int statz =0;
    map<int,int> dis,gift,bonus;
    cin >> n >> m;
    for(int i=1;i<=n-1;i++)
    {
        cin >> a >> b >> c;
        dis[i] = a;
        gift[i] = b;
        bonus[i] = c;
       // printf("%d %d %d \n",dis[i],gift[i],bonus[i]);
    }
    for(int i=1;i<=m;i++)
    {
        cin >> x >> y >> z;
        if(x>=dis[level])
        {
            if(statx == 0){
                statx = 1;
                exper++;
            }
        }
        if(y>=gift[level])
        {
            if(staty == 0){
                staty = 1;
                exper++;
            }
        }
        if(z>=bonus[level])
        {
            if(statz == 0){
                statz = 1;
                exper++;
            }
        }
        if(exper == 3)
        {
            level++;
            exper = 0;
            statx = 0;
            staty = 0;
            statz = 0;
           // cout << level << endl;
        }

    }

    if(level > n-1)
    {
         cout << n << endl;
    }else
    {
         cout << level << endl;
    }

}