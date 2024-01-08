#include <stdio.h>
#include <string.h>
#define p 11
#define q 5
#define n p×q
#define phi_n (p-1)*(q-1)

void rsa_key_generation();
int rsa_encryption();
int rsa_decryption();

int main()
{
    int public_key,private_key,message,ciper;
    printf("\nEnter the message to encrypt:\n");
    scanf("%d",&message);
    rsa_key_generation(&public_key,&private_key);
    cipher=rsa_encryption(message,public_key);
    printf("\nEncrypted Message is %d.",cipher);
    message=rsa_decryption(cipher,private_key);
    printf("\nDecrypted Message is %d.",message);
    return 0;
}

void rsa_key_generation(int* public_key,int* private_key)
{
   int seed=37;
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
    *public_key=(rand()%(phi_n-2))+2;
    }while(gcd(e,phi_n,0)==1);
    
    *private_key=gcd(*public_key,phi_n,1);
    
}

long long power(long long base,long long exp,long long mod)
{
    long long result=1;
    base= base % mod;
    
    while(exp>0)
    {
        if(exp % 2 ==0)
            result= (result*base) % mod;
        exp /= 2;
        base= (base*base) % mod;
    }
    return result;
}


int encryption(int message,int public_key)
{
    int cipher;
    cipher=power(message,public_key,n);
    return cipher;
}

int decryption(int cipher,int private_key)
{
    int message;
    message=power(cipher,private_key,n);
    return message;
}

