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
    printf("\n\t\tMENU");
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
    char plain_text[100],text[100];

    //Plain text input from User
    printf("\nPlain text to encrypt:\n");
    gets(text);
    
    //Text with only UPPERCASE alphabet character
    for(int i=0;i<strlen(text);i++)
    {
    if((text[i]>=65&&text[i]<=90)||text[i]>=97&&text[i]<=122)
    {
        plain_text[j]=toupper(text[i]);
        j++;
    }
    }
    
    //Plain text without formatting
    printf("\nPlain text with only alphabets:\n");
    for(int i=0;i<strlen(plain_text);i++)
    {
        printf("%c",plain_text[i]);
    }
    
    //Key input from User
    printf("\n\nEnter the Key to encrypt:");
    scanf("%d",&key);
   
    //Encryption algorithm
    for(int i=0;i<strlen(plain_text);i++)
    {
    plain_text[i]=((((plain_text[i]-65)+key)%26)+65);
    }
    
    //Ciphered text
    printf("\nThe encrypted message:\n");
    for(int i=0;i<strlen(plain_text);i++)
    {
        printf("%c",plain_text[i]);
    }
}
void decrypt(void)
{
    printf("yess!");
}
