#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define p 11
#define q 5
#define n(p,q) (p*q)
#define phi_n(p,q) ((p-1)*(q-1))

int input();
void rsa_key_generation(int*,int*);
int rsa_encryption(int,int);
int rsa_decryption(int,int);

int main()
{
    int message=input();
    int public_key,private_key,cipher;
    rsa_key_generation(&public_key,&private_key);
    cipher=rsa_encryption(message,public_key);
    printf("\nEncrypted Message is %d.",cipher);
    message=rsa_decryption(cipher,private_key);
    printf("\nDecrypted Message is %d.",message);
    return 0;
}

int input()
{
    /*
    char sentence[100];
    int message[100];
    printf("\nEnter the message to encrypt:\n");
    scanf("%s",&sentence);
    for (int i = 0; message[i] != '\0'; i++) 
    {
        message[i]=((int)sentence[i]);
    }
    */
    int message;
    do
    {
     printf("\nEnter the message to encrypt:\n");
     scanf("%d",&message);
    }while(message > n(p,q));
    
    return message;
}
    
int gcd(int a,int b,int c)
{
        if(c==0)
        {
        if(b==0)
        {
            return a;
        }
        gcd(b,a%b,0);
        }
        else
        {
            int quo,rem,t1=0,t2=1,t,temp;
            if(b>a)
            {
                temp=a;
                a=b;
                b=temp;
            }
            while(b != 0)
            {
                quo=a/b;
                rem=a%b;
                t=t1-t2*quo;
                a=b;
                b=rem;
                t1=t2;
                t2=t;
            }
            if(t1<0)
            {
                do
                 {
                   t1 += phi_n(p,q);
                   
                 }while(t1<0);
            }
            return t1;
        }
}

void rsa_key_generation(int* public_key,int* private_key)
{
    int seed=39;
    do
    {
    srand(seed++);
    *public_key=(rand()%(phi_n(p,q)-2))+2;
    }while(gcd(*public_key,phi_n(p,q),0) !=1);
    *private_key=gcd(*public_key,phi_n(p,q),1);
}

long long power(long long base,long long exp,long long mod)
{
    long long result=1;
    base= base % mod;
    
    while(exp>0)
    {
        if(exp % 2 ==1)
            result= (result*base) % mod;
        exp /= 2;
        base= (base*base) % mod;
    }
    return result;
}

int rsa_encryption(int message,int public_key)
{
    int cipher;
    cipher=power(message,public_key,n(p,q));
    return cipher;
}

int rsa_decryption(int cipher,int private_key)
{
    int message;
    message=power(cipher,private_key,n(p,q));
    return message;
}
