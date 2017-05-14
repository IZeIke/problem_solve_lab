#include <iostream>
#include <string>
#include <stdio.h>
#include<stack>
#include<vector>
using namespace std;

int n,m;
string ans = "no";
vector<bool> visited[900];



void start_run(vector<char>* map,int a,int b,int c)
{
    if(a == n-2)
    {
        ans = "yes";
    }
    else
    if(map[a+2][b] == '.' && map[a+2][c] == '.' && visited[a+2][b] != true && visited[a+1][b] != true && visited[a+2][c] != true && visited[a+1][c] != true) // down
    {
        visited[a][b] = true;
        visited[a][c] = true; 

        return start_run(map,a+1,b,c);
    }
    else
    if(map[a][b-1] == '.' && map[a+1][b-1] == '.' && visited[a][b-1] != true && visited[a+1][b-1] != true) // left
    {
        visited[a][b] = true;
        visited[a][c] = true;
        
        return start_run(map,a,b-1,b);
    }
    else
    if(map[a][c+1] == '.' && map[a+1][c+1] == '.' && visited[a][c+1] != true && visited[a+1][c+1] != true) // right
    {
        visited[a][b] = true;
        visited[a][c] = true;
    
        return start_run(map,a,c,c+1);
    }else
    if(map[a-1][b] == '.' && map[a-1][c] == '.' && visited[a-1][b] != true && visited[a-1][c] != true) // up
    {
        visited[a][b] = true;
        visited[a][c] = true;
    
        return start_run(map,a-1,b,c);
    }else
    {
        visited[a][b] = true;
        visited[a][c] = true;
        visited[a+1][b] = true;
        visited[a+1][c] = true;
        return;
    }
   
}

int main(){

    cin >> n >> m;

    vector<char> mymap[n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char str;
            cin >> str;
            mymap[i].push_back(str);
            visited[i].push_back(false);
        }
    }

    for(int i=0;i<m-1;i++)
    {
        if(mymap[0][i] == '.' && mymap[0][i+1] == '.' && mymap[1][i] == '.' && mymap[1][i+1] == '.')
        {
            start_run(mymap,0,i,(i+1));
        }

        if(ans == "yes")
        {
            break;
        }
    }

    cout << ans << endl;
}