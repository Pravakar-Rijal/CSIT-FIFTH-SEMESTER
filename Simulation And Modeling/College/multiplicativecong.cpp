#include <stdio.h>
int main()
{
	int n;
	printf("\nEnter the number of random integers to generate: ");
	scanf("%d",&n);
	int random_int[n],x0,a,m,x1;
	printf("\nEnter the initial seed value(X0): ");
	scanf("%d",&x0);
	printf("\nEnter the constant multiplier(a): ");
	scanf("%d",&a);
	printf("\nEnter the modulus(m): ");
	scanf("%d",&m);
	for(int i=0;i<n;i++)
	{
		x1=(a*x0) % m;
		random_int[i]=x1;
		x0=x1;
	}
	printf("\nThe random integers so generated are:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",random_int[i]);
	}
	return 0;
}
