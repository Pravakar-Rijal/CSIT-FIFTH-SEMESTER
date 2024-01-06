#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PRIME -1
#define NONPRIME 1
double power(double n,double p)
{
    double temp=1.0;
    while(p>0)
    {
        temp *= n;
        p--;
    }
    return temp;
}

void find_k_m(double n,double* a,double* b)
{
    double temp1;
    for(int i=0;i<n-1;i++)
    {
        temp1= fmod((n-1),power(2,i));
        if(!(temp1 == 0))
        {
             *a=i-1;
             *b= (n-1) / power(2,i-1);
             break;
        }
    }
}

void choose_a(double* a,double n)
{
    time_t t1;
    srand ( (unsigned) time (&t1)); 
    *a=(fmod((double)rand(),(n-1))) + 2.0;
}

int calc_b_values(double a,double m,double n)
{
    double b0;
    double result=pow(2,m);
    double num=n;
    //b0= power(2,m) % n;
    b0=fmod(result,num);
    return b0;
    while(b0==PRIME || b0==NONPRIME)
    {
    if(b0 == PRIME)
    return PRIME;
    else if(b0 == NONPRIME)
    return NONPRIME;
    else
    b0= fmod((b0*b0),n);
    }
}
int main() {
    double n,k,m,a;
    printf("\nEnter Number: ");
    scanf("%f",&n);
    find_k_m(n,&k,&m);
    choose_a(&a,n);
    if(calc_b_values(a,m,n)==PRIME)
    printf("\n%f is prime.",n);
    else if(calc_b_values(a,m,n)==NONPRIME)
    printf("\n%f is not prime.",n);
    else
    printf("k= %f m=%f a=%f calcvalues=%f.\n",k,m,a,calc_b_values(a,m,n));
    return 0;
}
