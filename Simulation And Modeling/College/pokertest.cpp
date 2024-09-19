#include <stdio.h>
#include <math.h>

#define N 10000
#define CR_VALUE 9.49

float sum(float*,int);

int main() {
    float expected_frequency[]={0.5040,0.4320,0.0270,0.0360,0.0010};
    int size=sizeof(expected_frequency)/sizeof(expected_frequency[0]);
    float observed_frequency[]={5120.0,4230.0,560.0,75.0,15.0};
    float chi_square_calc,chi_square[size];
      printf("\nOi\t\t");
    for(int i=0;i<size;i++)
    {
        printf("%.0f\t",observed_frequency[i]);
    }
    printf("\nEi\t\t");
    for(int i=0;i<size;i++)
{
    expected_frequency[i]= N * expected_frequency[i];
            printf("%.0f\t",expected_frequency[i]);
}
printf("\n(Oi-Ei)^2/Ei\t");
    for(int i=0;i<size;i++)
{
    chi_square[i]=(pow(observed_frequency[i]-expected_frequency[i],2))/expected_frequency[i];
    printf("%.2f\t",chi_square[i]);
}
chi_square_calc=sum(chi_square,size);
printf("\n\nSUM[(Oi-Ei)^2/Ei] => %.2f",chi_square_calc);
if(chi_square_calc < CR_VALUE)
{
    printf("\n\nSince, chi_square calculated(%.2f) < chi_square tabulated(%.2f)",chi_square_calc,CR_VALUE);
    printf("\nHypothesis that the generated numbers are independent is not rejected.");
}
else
{
      printf("\n\nSince, chi_square calculated(%.2f) > chi_square tabulated(%.2f)",chi_square_calc,CR_VALUE);
    printf("\nHypothesis that the generated numbers are independent is rejected.");
}
    return 0;
}

float sum(float a[],int n)
{
    float sum=0.0;
    for(int i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    return sum;
}
