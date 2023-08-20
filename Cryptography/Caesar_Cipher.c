//C PROGRAM TO IMPLEMENT CAESAR CIPHER ENCRYPTION ALGORITHM
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void menu(void);
void encrypt(void);
void decrypt(void);

int main()
{
    printf("<--------WELCOME TO CAESAR CIPHER PROGRAM-------->");
    menu();
    return 0;
}

void menu(void)
{
    int choice;
    printf("\n\n\t\tMENU");
    printf("\n\t\t1. Encryption");
    printf("\n\t\t2. Decryption");
    printf("\n\t\t3. Exit");
    printf("\n\t\tEnter your Choice:_");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        encrypt();
        break;
        case 2:
        decrypt();
        break;
        case 3:
        exit(1);
        break;
        default:
        printf("\nInvalid Command.");
        break;
    }
}

void encrypt(void) 
{
    //Necessary Variable Declarations
    int j=0,key;
    char text[100],plain_text[100],cipher_text[100];

    //Plain text input from User
    printf("\nPlain text to encrypt:\n");
    gets(plain_text);
    
    //Text with only UPPERCASE alphabet character
    for(int i=0;i<strlen(plain_text);i++)
    {
    if((plain_text[i]>=65&&plain_text[i]<=90)||plain_text[i]>=97&&plain_text[i]<=122)
     {
        text[j]=toupper(plain_text[i]);
        j++;
     }
    }
    
    //Plain text without formatting
    printf("\nPlain text with only alphabets:\n");
    for(int i=0;i<strlen(text);i++)
    {
        printf("%c",text[i]);
    }
    
    //Key input from User
    printf("\n\nEnter the Key to encrypt:");
    scanf("%d",&key);
   
    //Encryption algorithm
    for(int i=0;i<strlen(text);i++)
    {
    cipher_text[i]=((((text[i]-65)+key)%26)+65);
    }
    
    //Ciphered text
    printf("\nThe encrypted message:\n");
    for(int i=0;i<strlen(cipher_text);i++)
    {
        printf("%c",cipher_text[i]);
    }

    //Back to Menu
    menu();
}

void decrypt(void)
{
    // Necessary Variable Declarations
    int j=0,key;
    char text[100],cipher_text[100],plain_text[100];

    //Cipher text input from User
    printf("\nCiphered text to decrypt:\n");
    gets(cipher_text);
    
    //Text with only UPPERCASE alphabet character
    for(int i=0;i<strlen(cipher_text);i++)
    {
    if((cipher_text[i]>=65&&cipher_text[i]<=90)||cipher_text[i]>=97&&cipher_text[i]<=122)
     {
        text[j]=toupper(cipher_text[i]);
        j++;
     }
    }
    
    //Cipher text without formatting
    printf("\nCipher text with only alphabets:\n");
    for(int i=0;i<strlen(text);i++)
    {
        printf("%c",text[i]);
    }
    
    //Key input from User
    printf("\n\nEnter the Key to decrypt:");
    scanf("%d",&key);
   
    //Decryption algorithm
    for(int i=0;i<strlen(text);i++)
    {
    plain_text[i]=((((text[i]-65)-key)%26)+65);
    }
    
    //Deciphered text
    printf("\nThe decrypted message:\n");
    for(int i=0;i<strlen(plain_text);i++)
    {
        printf("%c",plain_text[i]);
    }
    //Back to Menu
    menu();
}
