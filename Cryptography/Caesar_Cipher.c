//C-PROGRAM TO IMPLEMENT CAESAR CIPHER
#include <stdio.h>
#include <string.h>

int main() 
{
    char alphabet[26];
    int key;
    char plain_text[1000];
    int ascii=65;
    //Assigning alphabet to array
    for(int i=0;i<26;i++)
    {
        alphabet[i]=ascii;
        ascii=ascii+1;
    }
   
    //Plain text input from User
    printf("\nPlain text to encrypt:\n");
    gets(plain_text);
   
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
