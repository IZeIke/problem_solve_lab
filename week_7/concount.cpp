#include <iostream>
#include <string>
#include <stdio.h>
#include<stack>
#include<vector>
using namespace std;


int main(){
    int p,n,a,b;
    scanf("%d %d",&p,&n);
    bool visited[100000];
    vector<int> node[100000];
    int deg[100000];
    stack<int> temp;

    for(int i=0;i<p;i++)
    {
        visited[i] = false;
        deg[i] = 0;
    }

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b); a--; b--;
        node[a].push_back(b);
        node[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    int count = 0;

    for(int i=0;i<p;i++)
    {
        if(!visited[i])
        {
            temp.push(i);
            while(!temp.empty())
            {
                int point = temp.top();
                temp.pop();
                
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
                    temp.push(chi);
                }
            }
            count++;
        }
    }

    cout << count << endl;

}