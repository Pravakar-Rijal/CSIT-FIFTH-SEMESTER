#include <stdio.h>
// function to convert decimal to hexadecimal
void decToHex(int decNum)
{
    // char array to store hexadecimal number
    char hexaDeciNum[50];
    // counter for hexadecimal number array
    int i = 0;
    while (decNum != 0)
    {
        /* temporary variable to
        store right most digit*/
        int temp = 0;
        // Get the right most digit
        temp = decNum % 16;
        // check if temp < 10
        if (temp < 10)
        {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else
        {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        decNum = decNum / 16; // get the quotient
    }
    printf("0x"); //print hex symbol
    // printing hexadecimal number array in reverse order
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hexaDeciNum[j]);
    }
}
int main()
{
    int decNum;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decNum);
    
    decToHex(decNum);
    return 0;
}
