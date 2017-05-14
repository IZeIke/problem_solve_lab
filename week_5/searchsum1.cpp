#include <vector>
#include <map>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,k;
    int p,m;
    vector<int> price; 
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> p;
        price.push_back(p);
    }
    
    for(int i=0;i<k;i++)
    {
        int c=0;
        cin >> m;
        for(int j = 0; j < price.size();j++)
        { 
            if(m >= price[j])
            {
                c++;
            }
            m = m - price[j];
        }
        cout << c << endl;
    }
}