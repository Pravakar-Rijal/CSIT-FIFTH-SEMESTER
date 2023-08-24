#include <stdio.h>

int max(int,int);
int gcd(int,int);

int main()
{	
	//Variable Declarations
	int mth_term,nth_term,gcd_arg1,gcd_arg2;
	
	//Mth and Nth term of fibonacci series with Validation
	do{
	printf("Enter the Mth term of fibonacci series:");
	scanf("%d",&mth_term);
	printf("Enter the Nth term of fibonacci series:");
	scanf("%d",&nth_term);
	}while(mth_term<0||nth_term<0);
	
	//Declaring and Initializing  with first three fibonacci numbers
	int fibo_series[max(mth_term,nth_term)]={0,1,1};
	
	//Storing fibonacci numbers in fibo_series
	for(int i=3;i<=max(mth_term,nth_term);i++)
	{
		fibo_series[i]=fibo_series[i-1]+fibo_series[i-2];	
	}
	
	//Sending integer values as arguments for gcd calculation
	gcd_arg1=fibo_series[mth_term];
	gcd_arg2=fibo_series[nth_term];
	printf("GCD of %d and %d is %d.",gcd_arg1,gcd_arg2,gcd(gcd_arg1,gcd_arg2));
	
	return 0;
}

//Function calculating maximum of two values
int max(int x,int y)
{
	if(x > y)
	return x;
	else
	return y;
}

//Function computing gcd of two fibonacci numbers
int gcd(int a,int b)
{
	if(a%b==0)
	return b;
	else
	gcd(b,a%b);
}
