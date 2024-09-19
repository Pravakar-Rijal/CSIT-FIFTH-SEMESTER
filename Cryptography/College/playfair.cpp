#include <stdio.h>

int check (char table [5][5],char k)
{
	int i,j;
	for(int i=0;i<5;i++)
	{
		for(j=0,j<5;j++)
		{
			if(table[i][j]==k)
			return 0;
		}
		return 1;
	}
}

int main()
{
	int i,j,key_len;
	char table[5][5];
	for(int i=0;i<5;i++)
	{
		for(j=0,j<5;j++)
		{
			table[i][j]='0';
		}
	}
	printf("Playfair Cipher\n\n");
	
	
	int plain_text[100],key;
	printf("Enter plain text: ");
	fgets(plain_text,100,stdin);
	printf("Enter key:")
	
	
	return 0;
}

