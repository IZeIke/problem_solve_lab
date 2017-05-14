#include <iostream>
#include <string>
#include <stdio.h>
#include<vector>
using namespace std;

int main()
{
    int Xi = 0;
    int Ci = 1;
    int Li = 2;
    int n,q;
    vector<int> panshop[100001];
    
    scanf("%d %d",&n,&q);

    for(int i=0;i<n;i++)
    {
        int X,C,L;
//        cin >> X >> C >> L;
        scanf("%d %d %d",&X,&C,&L);
        panshop[i].push_back(X);
        panshop[i].push_back(C);
        panshop[i].push_back(L);
    }

    for(int i=0;i<q;i++)
    {
        int min = 10000001;
        int sum = 0;
        int Y,minp;
       // cin >> Y;
        scanf("%d",&Y);
        for(int j=0;j<n;j++)
        {
            if(panshop[j][Xi] - Y <= 5 && panshop[j][Xi] - Y >= -5)
            {
                if(panshop[j][Li] > 0)
                {
                    sum = panshop[j][Ci];

                    if(sum < min)
                    {
                        min = sum;
                        minp = j;
                    }
                }

            } 
        }

        if(min == 10000001)
        {
            min = 0;
        }else{
            panshop[minp][Li] --;
        }

        printf("%d \n",min);
    }
}