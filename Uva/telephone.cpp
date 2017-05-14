#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cmath>  
using namespace std;

void letter(char* str)
{
    while(*str != '\0')
    {
        if(*str >= 65){
            if(*str <= 67)
            {
                cout << '2';
            }else
            if(*str <= 70)
            {
                cout << '3';
            }else
            if(*str <= 73)
            {
                cout << '4';
            }else
            if(*str <= 76)
            {
                cout << '5';
            }else
            if(*str <= 79)
            {
                cout << '6';
            }else
            if(*str <= 83)
            {
                cout << '7';
            }else
            if(*str <= 86)
            {
                cout << '8';
            }else
            if(*str <= 90)
            {
                cout << '9';
            }else
            {
                cout << *str;
            }
        }
        else
        {
            cout << *str;
        }
        
        str++;
    }
    cout << endl;;
}

int main()
{
    char str[100];
    //char strout[31];
    cin.getline(str,100);
    letter(str);
    //return 0;
}