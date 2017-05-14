#include <map>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,k;
    int p,m;
    int sum = 0;
    map<int,int> price,priceR;  
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &p);
        price[i] = p+sum;
        sum = price[i];
       // cout << price[i] << endl;
    }
    for(int i=1;i<=n;i++)
    {
        priceR[price[i]] = i;
        //cout << price[i] << endl;
    }

    for(int i=1;i<=k;i++)
    {
        scanf("%d", &m);
        if(m >= price[n])
        {
            cout << n << endl;
        }
        else
        if(priceR.find(m) != priceR.end())
        {
           // cout << (priceR.lower_bound(m)->second) << endl; 
            printf("%d\n", (priceR.lower_bound(m)->second));
        }
        else{
           // cout << (priceR.lower_bound(m)->second) -1<< endl;
            printf("%d\n", (priceR.lower_bound(m)->second) -1);
        }
        //cout << price.lower_bound(m)->first << endl;
    }
    
}