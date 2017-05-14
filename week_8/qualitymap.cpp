#include <iostream>
#include <string>
#include <stdio.h>
#include<stack>
#include<vector>
using namespace std;

int n,m;
int count = 0;
bool forest = false;
bool element = false;
vector<bool> visit[900];

void startrun(vector<char>* map,int row,int col)
{
    
    if (row < 0 || col < 0 || row == n || col == m) return;
    if (visit[row][col] || map[row][col] == '#') return;
    visit[row][col] = true;
    if (map[row][col] == '*')
        forest = true;
    if (map[row][col] == '$')
        element = true;

        count++;
     startrun(map,row+1, col);
     startrun(map,row-1, col);
     startrun(map,row, col-1);
     startrun(map,row, col+1);
}

int main(){

    cin >> n >> m;
    int best = 0;
    int good = 0;
    vector<char> mymap[n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char str;
            cin >> str;
            mymap[i].push_back(str);
            visit[i].push_back(false);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mymap[i][j] == '*' || mymap[i][j] == '$')
            {
                startrun(mymap,i,j);
                if(forest && element)
                {
                    best += count;
                }else
                if(forest || element)
                {
                    good += count;
                }
                
            }
            count = 0;
            forest = false;
            element = false;
        }
    }

    cout << best;
    cout << " ";
    cout << good << endl;

}

