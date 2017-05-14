#include <iostream>
#include <string>
#include <stdio.h>
#include<vector>
using namespace std;

vector<vector<bool> > visited;

int running(vector<vector<int> > board,int i,int j,int n,int k)
{
    if(board[i][j] == board[n][n])
    {
        return 1;
    }

    if(board[i-1][j] != '\0')
    {
        if(board[i-1][j] <= board[i][j]+k)
        {
            return running(board,i-1,j,n,k);
        }
    }else
    if(board[i][j+1] != '\0')
    {
        if(board[i][j+1] <= board[i][j]+k)
        {
            return running(board,i,j+1,n,k);
        }
    }else
    if(board[i+1][j] != '\0')
    {
        if(board[i+1][j] <= board[i][j]+k)
        {
            return running(board,i+1,j,n,k);
        }
    }else
    if(board[i][j-1] != '\0')
    {
        if(board[i][j-1] <= board[i][j]+k)
        {
            return running(board,i,j-1,n,k);
        }
    }else
    {
        return 0;
    }
}

int main()
{
    int n,k,high;
    cin >> n >> k;    
    vector<vector<int> > board;
    board.resize(n);
  for (int i = 0; i < n; ++i)
    board[i].resize(n);

    visited.resize(n);
  for (int i = 0; i < n; ++i)
    visited[i].resize(n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> high;
            board[i][j] = high;
            visited[i][j] = false;
        }
    }
    int ans = running(board,0,0,n-1,k); 
    if(ans == 0)
    {
        printf("no \n");
    }else
    {
        printf("yes \n");
    }
}



