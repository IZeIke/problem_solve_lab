#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <cmath>  
using namespace std;

int main()
{
    int n,k;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> k;
        char str[k];
        double value[k];
        for (int j = 0; j < k; j++)
        {
            str[j] = 0;
            value[j] = 0;
        }
        for(int j=0;j<k;j++)
        {
            char s;
            scanf(" %c%lf",&s,&value[j]);
            str[j] = (unsigned char)s;
        }
        int m;
        int sum = 0;
        scanf("%d",&m);
        for(int j=0;j<m+1;j++)
        {
            char article[10001];
            cin.getline(article,10001);
            char* head = article;
            //cout << *head << endl;
            for(int l=0;l<k;l++)
            {
                char* save = head;
                while(*head != '\0')
                {
                    if((unsigned char)*head == str[l])
                    {
                        sum += value[l];
                    }
                    head++;
                }
                head = save;
            }
        }
        int y = sum % 100;
        double x = sum / 100;
        cout << x ;
        cout << ".";
        if(y == 0)
        {
            cout << "00";
        }else{
            cout << y;
        }
        cout << "$" << endl;
        sum = 0;
    }
}