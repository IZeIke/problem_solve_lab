#include <iostream>
#include <string>
#include<math.h>
using namespace std;

int main()
{
    int n,a,b,R,x,y;
    int minus_x = 0;
    int minus_y = 0;
    int c = 0;
    cin >> n >> a >> b >> R;
    if(a != 0)
    {
        minus_x = a;
        a = 0;
    }
    if(b != 0)
    {
        minus_y = b;
        b = 0;
    }
    for(int i = 0;i<n;i++)
    {
        cin >> x >> y;
        x = x - minus_x;
        y = y - minus_y;
        if(sqrt(x*x+y*y) <= R)
        {
            c++;
        }
    }
    cout << c << endl;
}