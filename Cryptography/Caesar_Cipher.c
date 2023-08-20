
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() 
{
    int key;
    int j=0;
    char plain_text[100],text[100];

    //Plain text input from User
    printf("\nPlain text to encrypt:\n");
    gets(text);
    for(int i=0;i<strlen(text);i++)
    {
    if((text[i]>=65&&text[i]<=90)||text[i]>=97&&text[i]<=122)
    {
        plain_text[j]=toupper(text[i]);
        j++;
    }
    }
    for(int i=0;i<strlen(plain_text);i++)
    {
        printf("%c",plain_text[i]);
    }
    //Key input from User
    printf("\nEnter the Key to encrypt:");
    scanf("%d",&key);
   
    //Encryption algorithm
    for(int i=0;i<strlen(plain_text);i++)
    {
    plain_text[i]=(plain_text[i]+key);
    }
    
    //Ciphered text
    printf("\nThe encrypted message:\n");
    for(int i=0;i<strlen(plain_text);i++)
    {
        printf("%c",plain_text[i]);
    }

    return 0;
    
}
