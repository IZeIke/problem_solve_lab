#include <iostream>
#include <string>
#include <stdio.h>
#include<map>
using namespace std;

int select_team(map<int,int> s1,map<int,int> s2,map<int,int> s3,map<int,int> s4,int i,int j)
{
    if(i == 1)
    {
        return s1[j];
    }else
    if(i == 2)
    {
        return s2[j];
    }else
    if(i == 3)
    {
        return s3[j];
    }else
    {
        return s4[j];
    }
}

int main()
{
    string str;
    map<int,string> county;
    for(int i=1;i<=4;i++)
    {
        cin >> str;
        county[i] = str;
    }
    map<int,int> score1;
    map<int,int> score2;
    map<int,int> score3;
    map<int,int> score4;
    map<int,int> sumshoot;
    int score;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(i == j)
            {
                cin >> score;
                score = 0;
            }else{
                cin >> score;
            }

            if(i==1)
            {
                score1[j] = score;
                sumshoot[i] += score;
            }else
            if(i==2)
            {
                score2[j] = score;
                sumshoot[i] += score;
            }else
            if(i==3)
            { 
                score3[j] = score;
                sumshoot[i] += score;
            }else
            if(i==4)
            {
                score4[j] = score;
                sumshoot[i] += score;
            }
        }
    }
    int c = 0;
    map<int,int> score_sum;
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
                if(i != j)
                {
                    if(select_team(score1,score2,score3,score4,i,j) > select_team(score1,score2,score3,score4,j,i))
                    {
                        c=c+3;
                    }else
                    if(select_team(score1,score2,score3,score4,i,j) == select_team(score1,score2,score3,score4,j,i))
                    {
                        c++;
                    }else{}
                }  
        }
        score_sum[i] = c;
        c = 0;
    }
    map<int,int> present_pos;
    present_pos[1] = 1;
    present_pos[2] = 2;
    present_pos[3] = 3;
    present_pos[4] = 4;
    for(int i=1;i<=4;i++)
    {
        for(int j = 1;j<=4-i;j++)
        {
            if(score_sum[j]>score_sum[j+1])
            {
                int a = score_sum[j];
                score_sum[j] = score_sum[j+1];
                score_sum[j+1] = a;
                int b = present_pos[j];
                present_pos[j] = present_pos[j+1];
                present_pos[j+1] = b;
            }else
            if(score_sum[j] == score_sum[j+1])
            {
                if(sumshoot[present_pos[j]] > sumshoot[present_pos[j+1]])
                {
                    int c = present_pos[j];
                    present_pos[j] = present_pos[j+1];
                    present_pos[j+1] = c;
                }
            }
        }   
    }

    for(int i=4;i>=1;i--)
    {
        cout << county[present_pos[i]];
        cout << " ";
        cout << score_sum[i] << endl;
    }
}