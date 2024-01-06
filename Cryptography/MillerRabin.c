
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int power(int n,int p)
{
    int temp=1;
    while(p>0)
    {
        temp *= n;
        p--;
    }
    return temp;
}
void powerof2 (int n,int* a,int* b)
{
    float temp1;
    for(int i=0;i<n;i++)
    {
        temp1= n % power(2,i);
        if(!(temp1 == 0))
        {
             *a=i-1;
             *b= n / power(2,i-1);
             break;
        }
    }
}

int main() {
    int n,k,m,a;
    time_t t1;
    printf("\nEnter Number: ");
    scanf("%d",&n);
    powerof2(n,&k,&m);
    srand ( (unsigned) time (&t1)); 
    a=(rand() % (n-1)) + 2;
    
    printf("\nNearest power of 2 is %d %d %d.\n",k,m,a);
    return 0;
}
