//Conversion from decimal to hexadecimal
#include <stdio.h>
#include <math.h>

void convert_to_hexa(int);

int main()
{
	long int deci_num;
	printf("Enter a Decimal Number: ");
	scanf("%ld",&deci_num);
	convert_to_hexa(deci_num);
	return 0;
}
void convert_to_hexa(int deci_num)
{
	long quo,rem=0;
	int i,j;
	char hexa_num[100];
	quo=deci_num;
	while(quo!=0);
	{
		rem=quo%16;
	if(rem<10)
	{
	hexa_num[j++]=48+rem;
	}
	else
	{
		hexa_num[j++]=55+rem;
		quo=quo/16;
	}
	}
	for(i=0;i>=10;i--)
	{
		printf("%c",hexa_num[i]);
	}
}
