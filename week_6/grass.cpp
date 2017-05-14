#include <iostream>
#include <string>
#include <stdio.h>
#include<map>
#include<vector>
using namespace std;

int main(){
    int m,n;
    cin >> n >> m;
    char str,order;
    vector<vector<char> > grass;
    grass.resize(n+2);
  for (int i = 0; i < n+1; ++i)
    grass[i].resize(n+2);


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> str; 
            grass[i][j] = str;             
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         printf("%c", grass[i][j]);
    //     printf("\n");
    // }

    int k;
    for(int j=0;j<m;j++)
    {
        cin >> order;
        cin >> k;
        // cout << order << "**" << endl;
        if(order == 'L')
        {
            for(int i=1;i<=n;i++)
            {
                if(grass[k][i] == 'x')
                {
                    grass[k][i] = '.';
                }else
                if(grass[k][i] == '#' || grass[k][i] == '.')
                {
                    break;
                }
            }
        }else
        if(order == 'R')
        {
            for(int i=n;i>=1;i--)
            {
                if(grass[k][i] == 'x')
                {
                    grass[k][i] = '.';
                }else
                if(grass[k][i] == '#' || grass[k][i] == '.')
                {
                    break;
                }
            }
        }else
        if(order == 'U')
        {
            for(int i=1;i<=n;i++)
            {
                if(grass[i][k] == 'x')
                {
                    grass[i][k] = '.';
                }else
                if(grass[i][k] == '#' || grass[i][k] == '.')
                {
                    break;
                }
            }
        }else
        if(order == 'D')
        {
            for(int i=n;i>=1;i--)
            {
                if(grass[i][k] == 'x')
                {
                    grass[i][k] = '.';
                }else
                if(grass[i][k] == '#' || grass[i][k] == '.')
                {
                    break;
                }
            }
        }else
        if(order == 'A')
        {
            for(int i=1;i<=n;i++)
            {
                if(grass[k][i] == '.')
                {
                    grass[k][i] = 'x';
                }
            }
        }else
        if(order == 'B')
        {
            for(int i=1;i<=n;i++)
            {
                if(grass[i][k] == '.')
                {
                    grass[i][k] = 'x';
                }
            }
        }
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
             
            cout << grass[i][j];
                   
        }
        cout << "" << endl; 
    }
  
}