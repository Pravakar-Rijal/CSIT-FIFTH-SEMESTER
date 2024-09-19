#include <stdio.h>
#include <string.h>

void enc(char p[100], int k)
{
    int l = strlen(p);
    char store[l];
    int j = 0;

    for (int count = 0; count < k; count++)
    {
        int i = count;
        int s1 = (k - count - 1) * 2;
        int s2 = count * 2;

        while (i < l)
        {
            store[j++] = p[i];
            if (s1 > 0 && i + s1 < l)
                i += s1;
            else if (s2 > 0 && i + s2 < l)
                i += s2;
            else
                break;
        }
    }
    store[j] = '\0';
    printf("Cipher text: %s", store);
}

void dec(char p[], int k)
{
    int l = strlen(p);
    char store[l];
    int rail[k][l];
    memset(rail, 0, sizeof(rail));

    int r = 0;
    int d = 0;

    for (int i = 0; i < l; i++)
    {
        rail[r][i] = 1;
        if (r == 0)
            d = 0;
        else if (r == k - 1)
            d = 1;
        if (d == 0)
            r++;
        else
            r--;
    }

    int index = 0;

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (rail[i][j] == 1)
                store[j] = p[index++];
        }
    }

    store[l] = '\0';
    printf("Decrypted text: %s\n", store);
}

int main()
{
    int k, ch;
    char p[100];

    printf("Enter the message: ");
    gets(p);
    printf("Enter the depth: ");
    scanf("%d", &k);
    printf("Select\n1.Encryption\n2.Decryption\n: ");
    scanf("%d", &ch);

    if (ch == 1)
        enc(p, k);
    else if (ch == 2)
        dec(p, k);
    else
        printf("Invalid input");

    return 0;
}
