#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to perform Vigenere encryption or decryption
void vigenereCipher(char *text, char *key, int encrypt) {
    int textLen = strlen(text);
    int keyLen = strlen(key);

    for (int i = 0; i < textLen; i++) {
        if (isalpha(text[i])) {
            // Adjust key index based on the current character in the text
            int keyIndex = i % keyLen;

            // Determine the shift value based on the key character
            int shift;
            if (isupper(key[keyIndex])) {
                shift = key[keyIndex] - 'A';
            } else {
                shift = key[keyIndex] - 'a';
            }

            // Apply the shift to the current character in the text
            if (isupper(text[i])) {
                if (encrypt) {
                    text[i] = (text[i] - 'A' + shift) % 26 + 'A';
                } else {
                    text[i] = (text[i] - 'A' - shift + 26) % 26 + 'A';
                }
            } else {
                if (encrypt) {
                    text[i] = (text[i] - 'a' + shift) % 26 + 'a';
                } else {
                    text[i] = (text[i] - 'a' - shift + 26) % 26 + 'a';
                }
            }
        }
    }
}

int main() {
    char plaintext[1000];
    char key[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters from input
    strtok(plaintext, "\n");
    strtok(key, "\n");

    // Encrypt the plaintext using the Vigenere Cipher
    vigenereCipher(plaintext, key, 1);

    printf("Encrypted text: %s\n", plaintext);

    // Decrypt the encrypted text
    vigenereCipher(plaintext, key, 0);

    printf("Decrypted text: %s\n", plaintext);

    return 0;
}
