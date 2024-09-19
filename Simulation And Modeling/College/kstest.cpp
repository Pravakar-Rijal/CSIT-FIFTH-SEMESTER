#include <stdio.h>
#define D_alpha 0.565

void sort(float*,int);
float ks_test(float*,int);
float max(float*,int);

int main() {
    float random_num[]={0.54,0.73,0.98,0.11,0.68,0.45};
    float D_calculated;
    int size=sizeof(random_num)/sizeof(random_num[0]);
    sort(random_num,size);
    printf("\nR(i)\t\t");
    for(int i=0;i<size;i++)
    {
        printf("%.2f\t",random_num[i]);
    }
    D_calculated=ks_test(random_num,size);
    if(D_calculated < D_alpha)
    {
        printf("\n\nSince, D_calculated(%.2f) < D_alpha(%.3f)",D_calculated,D_alpha);
        printf("\nHypothesis that the distribution of the generated numbers is uniform is not rejected.");
    }
    else
    {
        printf("\n\nSince, D_calculated(%.2f) > D_alpha(%.3f)",D_calculated,D_alpha);
        printf("\nHypothesis that the distribution of the generated numbers is uniform is rejected.");
    }
    return 0;
}

void sort(float a[],int size)
{ 
  float swap;
for(int i=0;i<size-1;i++)
{
    for(int j=0;j<size-i-1;j++)
    {
        if(a[j]>a[j+1])
        {
            swap=a[j];
            a[j]=a[j+1];
            a[j+1]=swap;
        }
    }
}

}

float ks_test(float random_num[],int size)
{
    float D_plus[size],D_minus[size],max_D_plus,max_D_minus,max_D;
    float i=1.0;
    printf("\n(i/N)-R(i)\t");    
    for(int j=0;j<size;j++)
    {
        D_plus[j]=(i/size)-random_num[j];
        
        printf("%.2f\t",D_plus[j]);
        D_minus[j]=random_num[j]-((i-1)/size);
        i++;
    }
    printf("\nR(i)-(i-1)/N\t");   
        for(int j=0;j<size;j++)
    {
        printf("%.2f\t",D_minus[j]);
    }
    max_D_plus=max(D_plus,size);
    printf("\n\nmax(D+)=%.2f",max_D_plus);
    max_D_minus=max(D_minus,size);
    printf("\nmax(D-)=%.2f",max_D_minus);
    max_D=(max_D_plus > max_D_minus) ? max_D_plus : max_D_minus;
     printf("\nmax(D)=%.2f",max_D);
    return max_D;
}

float max(float a[],int size)
{
    float max=a[0];
    for(int i=0;i<size;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    return max;
}
