#include <iostream>
#include <string>
#include <stdio.h>
#include<map>
using namespace std;

int count_syllables(char* a)
{
    int c = 0;
    char* head = a;
    char status = '0';
    char past = '0';
    while(*a != '\0')
    {
        if(*a == 'a' || *a == 'e' || *a == 'i' || *a == 'o' || *a == 'u')
        {
            status = '1';
            if(a == head)
            {
                c++;
            }else
            if(past != '1')
            {
                c++;
            }
        }else
        {
            status = '0';
        }
        past = status;
        a++;
    }
    return c;
}

int main()
{
    int n;
    int i;
    scanf("%d",&n);
    for(int j=1;j<=n;j++)
    {
        char a[31];
        scanf("%s",a);
        i = count_syllables(a);
        cout << i << endl;   
    }
}