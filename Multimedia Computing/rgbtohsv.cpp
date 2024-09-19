//Conversion from RGB to HSV
#include <stdio.h>

#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define NO_HUE 0

void rgbtohsv(float r,float g,float b)
{
	float h,s,v;
	float max=MAX(r,MAX(g,b)),min=MIN(r,MIN(g,b));
	float delta= max-min;
	v=max;
	if(max!=0.0)
	s=delta/max;
	else
	s=0.0;
	if (s==0.0)
	h=NO_HUE;
	else
	{
		if(r==max)
		h=(g-b)/delta;
		else if (g=max)
		h=2+(b-r)/delta;
		else if(b==max)
		h=4+(r-g)/delta;
		h*=60.0;
		if(h<0)
		h+=360.0;
		h/=360.0;
	}
	printf("\nH=%f\nS=%f\nV=%f\n",h,s,v);
}

int main()
{
	float a,b,c;
	printf("Enter the RGB:\n");
	scanf("%f %f %f",&a,&b,&c);
	printf("\nThe HSV Value:");
	rgbtohsv(a,b,c);
	return 0;
}
