#include <iostream>
#include <string>
#include <stdio.h>
#include<map>
#include<vector>
using namespace std;

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    map<int,int> size;
    int max = -1;
    for(int i=0;i<n;i++)
    {
        cin >> size[i];
        if(size[i] > max)
        {
            max = size[i];
        }
    }

    map<int,int> minsize;
    int sum = 0;
    for(int i=max;i<=b;i++)
    {
        sum = 0;
        for(int j=0;j<n;j++)
        {
            sum += size[j];
            if(sum < i && j == (n-1))
            {
                minsize[i] += i-sum;
            }else
            if(sum > i)
            {
                if(j == (n-1))
                {
                    minsize[i] += (i - (sum - size[j]));
                    minsize[i] += (i-size[j]);
                }else{
                    minsize[i] += (i - (sum - size[j]));
                    sum = size[j];
                }
            }else
            if(sum == i)
            {
                sum = 0;
            }else{}
        } 
    }

    int min;
    for(int i=max;i<=b;i++)
    {
       // printf("%d %d\n", i, minsize[i]);
        if(minsize[i] < min || i == max)
        {
            min = minsize[i];
        }
    }
    
    for(int i=max;i<=b;i++)
    {
        if(minsize[i] == min)
        {
            cout << i << endl;
            break;
        }
    }
}