#include <iostream>
#include <string>
#include <stdio.h>
#include<vector>
using namespace std;

int p,n,a,b,weight;
bool visited[100000];
vector<int> node[100000];
vector<int> weight_2p[100000];
int deg[100000];
int weight_p[100000];


void init_instance()
{ 
    int max = 1000000;

    for(int i=0;i<p;i++)
    {
        visited[i] = false;
        deg[i] = 0;
        weight_p[i] = max;
    }
    weight_p[0] = 0;
}

int main()
{
    scanf("%d %d",&p,&n);

    init_instance();

    vector<vector<int> > weight_2p;
    weight_2p.resize(p);
    for (int i = 0; i < p; ++i)
        weight_2p[i].resize(p);
    
    for(int i=0;i<n;i++)
    {
        //printf("%d \n",i);
        scanf("%d %d %d",&a,&b,&weight); a--; b--;
        node[a].push_back(b);
        node[b].push_back(a);
        weight_2p[a][b] = weight;
        weight_2p[b][a] = weight;
        deg[a]++;
        deg[b]++;
    }

    int min = 100001;
    int current_p = 0;
    int sum_length = 0;
    int next_p = 0;
    int temp = 0;

    while(true)
    {
        for(int i=0;i < deg[current_p];i++)
        {
            if(visited[node[current_p][i]] == true)
            {
                continue;
            }

            sum_length += weight_2p[current_p][ node[current_p][i] ];

            if(sum_length < weight_p[ node[current_p][i] ])
            {
                weight_p[ node[current_p][i] ] = sum_length;
            }

            if(node[current_p][i] == p-1)
            {
                min = sum_length;
                temp = weight_2p[current_p][ node[current_p][i] ];
                next_p = node[current_p][i];
                sum_length -= weight_2p[current_p][ node[current_p][i] ];
                break;
            }
          //  if(current_p == 2)
          //  {
          //      printf("%d from node %d \n",sum_length,node[current_p][i]);
          //  }

            if(sum_length < min){
                min = sum_length;
                temp = weight_2p[current_p][ node[current_p][i] ];
                next_p = node[current_p][i];
            }

            sum_length -= weight_2p[current_p][ node[current_p][i] ];

        }
        visited[current_p] = true;
        sum_length += temp;
        if(next_p == p-1)
        {
            printf("%d \n",sum_length);
            break;
        }
       // printf("%d \n",next_p);
       // printf("%d \n",sum_length);
        current_p = next_p;
        min = 100001;
    }

}