#include <stdio.h>

int isprime (int);
void primefactors(int);

int main() 
{
    int num;
    printf("\nEnter a number to find prime factors of: ");
    scanf("%d",&num);
    printf("\nThe prime factors of %d are ",num);
    primefactors(num);
    return 0;
}

void primefactors (int num)
{
      for(int i=2;i<=num/2;i++)
    {
        if(num%i == 0)
        {
        if(isprime(i))
        {
            printf("%d ",i);
        }
        }
    }
}

int isprime (int n)
{
    for(int i=2;i<=n/2;i++)
    {
        if(n%i == 0)
        {
            return 0;
        }
    }
    return 1;
}
