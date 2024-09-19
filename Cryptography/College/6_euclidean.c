// C program to demonstrate Basic Euclidean Algorithm
#include<stdio.h>

// Function to return gcd of a and b
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

// Driver program to test above function
int main()
{
    int a,b;
	printf("enter the two numbers\n");
    scanf("%d%d",&a,&b);
	printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));
	
	return 0;
}
