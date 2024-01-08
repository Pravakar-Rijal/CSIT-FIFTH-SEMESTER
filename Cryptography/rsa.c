#include <stdio.h>
#include <string.h>
#define p 11
#define q 5

int public_key;

int rsa_key_generation();
int rsa_encryption();
int rsa_decryption();

int main()
{
    int message,ciper;
    printf("\nEnter the message to encrypt:\n");
    scanf("%d",&message);
    rsa
    cipher=rsa_encryption(message);
    printf("\nEncrypted Message is %d.",cipher);
    message=rsa_decryption(cipher);
    printf("\nDecrypted Message is %d.",message);
    return 0;
}

int rsa_key_generation()
{
   int n,phi_n,seed=37,private_key;
    n=p×q;
    phi_n=(p-1)*(q-1);
   
    int gcd(int a,int b,int c)
    {
        if(c==0)
        {
        if(b==0)
        {
            return a;
        }
        gcd(b,a%b);
        }
        else
        {
            int q,r,t1=0,t2=1,t,temp;
            if(b>a)
            {
                temp=a;
                a=b;
                b=temp;
            }
            while(b != 0)
            {
                q=a/b;
                r=a%b;
                t=t1-t2*q;
                a=b;
                b=r;
                t1=t2;
                t2=t;
            }
            return t1;
        }
    }
    
    do
    {
    srand(seed++);
    public_key=(rand()%(phi_n-2))+2;
    }while(gcd(e,phi_n,0)==1);
    
    private_key=gcd(public_key,phi_n,1);
    
}

int encryption 

