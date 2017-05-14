#include <iostream>
#include <string>
#include <stdio.h>
#include<stack>
#include<vector>
using namespace std;

int jump(int i,int* value,int* sum)
{
        if(i == 2)
        {
            sum[i] = value[i];
        }
        else
        {
            if(value[i]+sum[i-3] > sum[i-1])
            {
                sum[i] = value[i]+sum[i-3];
            }else
            {
                sum[i] = sum[i-1];
            }
        }
        return sum[i];
}

int main()
{
    int n;
    int ans = 0;
    cin >> n;
    int value[n];
    int sum[n];
    for(int i=0;i<n;i++)
    {
        cin >> value[i];
        sum[i] = 0;
    }

    for(int i=2;i<n;i++){
        ans = jump(i,value,sum);
    }

    cout << ans << endl;
}