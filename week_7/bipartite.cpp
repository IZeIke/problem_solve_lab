#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include<vector>
#include<stack>
using namespace std;

int k,n,m;
vector<int> node[100000];
bool visited[100000];
int deg[100000];
int level[100000];
stack<int> temp;
string ans = "yes";

void read_input()
{
    cin >> n >> m;

    for(int j=0;j<n;j++)
    {
        node[j].clear();
        level[j] = 0;
        deg[j] = 0;
        visited[j] = false;
    }


    for(int j=0;j<m;j++)
    {
        int u,v;
        cin >> u >> v; u--; v--;
        node[u].push_back(v);
        node[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    
}

void dfs(int i)
{
    temp.push(i);

    while(!temp.empty())
    {
        int point = temp.top();
        temp.pop();
        if(level[point] == 0)
        {
            level[point] = 1;
        }        
        if(!visited[point])
        {
            visited[point] = true;
        }else
        {
            continue;
        }
    
        for(int i=deg[point]-1;i>=0;i--)
        {
            int chi = node[point][i];
            if(level[chi] == 0){
                if(level[point] == 1)
                {
                    level[chi] = -1;
                }else
                {
                    level[chi] = 1;
                }
            }

            if(level[point] == level[chi])
            {
                ans = "no";
            }

            temp.push(chi);
        }
    }
}

int main()
{
    cin >> k;    

    for(int i=0;i<k;i++)
    {
        read_input();

        for(int j=0;j<n;j++)
        {
            if(!visited[j])
            {
                dfs(j);
            }
        }
        cout << ans << endl;
        ans = "yes";
    }
}