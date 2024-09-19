#include <stdio.h>
#include <string.h>

void encrypt(char plaintext[],char key[]);
void decrypt(char plaintext[],char key[]);

int main()
{
	char plaintext[100];
	char ciphertext[100];
	char key;
	printf("Enter plaintext: ");
	fgets(plaintext,100,stdin);
	printf("Enter Keyword: ");
	fgets(key,100,stdin);
	plaintext[strcspn(plaintext,"\n")]='\0';
	key[strcspn(key,"\n")]='\0';
	encrypt(plaintext,key);
	printf("Encrypted text:%s\n",plaintext);
	decrypt(plaintext,key);
	printf("Decrypted text:%s\n",plaintext);
	return 0;
}

void encrypt(char plaintext[],char key[])
{
	int i,j,key_len;
	char ch;
	key_len=strlen(key);
	for(i=0;j=0;plaintext[i]!='\0';++i,++j)
	{
		ch=plaintext[i];
	if(ch>='A'&&ch<='Z')
	{
		ch=(ch+key[]%key_len)-'A'*2)%26+'A';
	}
	else if (ch>='a'&&ch<='z')
	{
		ch=(ch+key[]%key_len)-'a'*2)%26+'a';
	}
	plaintext[i]=ch;
	}
}

void decrypt(char ciphertext[],char key[])
{
	int i,j,key_len;
	char ch;
	key_len=strlen(key);
	for(i=0;j=0;ciphertext[i]!='\0';++i,++j)
	{
		ch=plaintext[i];
	if(ch>='A'&&ch<='Z')
	{
		ch=(ch+key[]%key_len)-'A'*2)%26+'A';
	}
	else if (ch>='a'&&ch<='z')
	{
		ch=(ch+key[]%key_len)-'a'*2)%26+'a';
	}
	plaintext[i]=ch;
	}
}
