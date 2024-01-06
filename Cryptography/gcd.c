#include <stdio.h>

int gcd(int a,int b)
{
if(b==0)
{
    return a;
}
gcd(b,a%b);
}

int main() {
    int a,b;
    printf("\nEnter two numbers to find GCD of:\t");
scanf("%d %d",&a,&b);
printf("\nGCD of %d and %d is %d.\n",a,b,gcd(a,b));
return 0;
}
