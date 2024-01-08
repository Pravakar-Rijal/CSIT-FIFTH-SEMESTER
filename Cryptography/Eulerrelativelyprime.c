#include <stdio.h>

float phi(int n)
{
    int k=0;
    float result=1.0;
    float totient;
    float arr[10]={0};
    
    for(int i=2;i<=n/2;i++)
    {
        if(n%i == 0)
        {
            for(int j=2;j<=i/2;j++)
            {
                if(!(i%j == 0))
                {
                    arr[k]=i;
                    k++;
                }
                
            }
        }
    }
    
    for(int i=0; arr[i]!=0;i++ )
    {
        result *= (1.0-(1.0/arr[i]));
    }
    
    totient= n*result;
    printf("%f",totient);
    return totient;
}


long long power(int a,int b)
{
    long long power=1;
    while(b>0)
    {
        power *= a;
        b--;
    }
    return power;
}
int main(){
    int a,n,expression;
    printf("\nEnter two numbers:");
    scanf("%d %d",&a,&n);
    expression=power(a,phi(n)) % n;
    if(expression == 1)
    {
        printf("\n%d and %d are relatively prime.",a,n);
    }
    else
    {
        printf("\n%d and %d are not relatively prime.",a,n);
    }
    
    return 0;
}
