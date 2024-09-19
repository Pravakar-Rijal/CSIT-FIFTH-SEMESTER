// c=(p+k) mod 26, p=c-k mod 26  output=input+-key mod 26


#include <stdio.h>
#include <strings.h>
#include<ctype.h>
void encDec(char p[100], int k)
{
    for (int i = 0; i < strlen(p); i++) 
    {
            p[i]=toupper(p[i]);
            p[i] = (p[i] - 'A' + k) % 26 + 'A';
        }

    

}
int main()
{
    int k,ch;
    char  p[100];
    printf("Enter the message: ");
    gets(p);
    printf("Enter the key: ");
    scanf("%d", &k);
    printf("Select\n1.Encryption \n2.Decryption\n: ");
    scanf("%d", &ch);
    if(ch==1){
        encDec(p, k);
        printf("The cipher text is %s",p);

    }
    else if(ch==2){
        encDec(p, 26-k);
        printf("The plain text is %s",p);
    }
    else{
        printf("Invalid input");
    }

    return 0;
}