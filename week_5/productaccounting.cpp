#include <map>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,k,A,B;
    map<int ,int> product;
    scanf("%d", &n);
    //cin >> n;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &k);
       // cin >> k;
        if(k == 1)
        {
            scanf("%d %d", &A, &B);
            //cin >> A >> B;
            if(product.find(A) != product.end())
            {
                product[A] += B;
            }else{
                product[A] = B;
            }
        }else 
        if(k == 2)
        {
            scanf("%d",&A);
         //   cin >> A;
            if(product.find(A) != product.end())
            {
                printf("%d \n",product[A]);
            }else{
                printf("%d \n",0);
            }
        }else
        if(k == 3)
        {
            scanf("%d %d",&A,&B);
         //   cin >> A >> B;
            if(product.find(A) != product.end())
            {
                if(B <= product[A])
                {
                    product[A] = product[A] - B;
                    printf("%d \n",B);
                }else{
                    printf("%d \n",product[A]);
                    product[A] = 0;
                }  
            }else{
                printf("%d \n",0);
            }
        }
    }
}