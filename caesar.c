#include <stdio.h>
#include "cs50.h"
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


/*
Caesar Key encrypter v1.0 - Developed by Arsalan Ghassemi
*/

// Variables and functions declarations
int key;
void getPlaintext();
void caesarCipher();
string plaintext;

/*
Hello ! This is the Caesar Key encrypter made for the problem set 2 of CS50's Introduction to Computer Science course.
The user should input the key in the command prompt after the ./caesar key (key as a number) command.

The software works as follows :

1 . Get the users input and checks if it's valid
2 . Assigns the key entered by the user to an integer
3 . Gets the plain text from the user
4 . Ciphers the text using Caesar's cipher method
5 . Prints back the ciphered text in result for the user.

Feel free to send any suggestions at contact@arsadevs.com 
*/

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int a = 0; a < strlen(argv[1]); a++)
    {
        if (isdigit(argv[1][a]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    key = atoi(argv[1]);
    getPlaintext();
    caesarCipher();
    return 0;
}


void getPlaintext()
// First function to get the plain text from the user
{
    plaintext = get_string("plaintext: ");
}


void caesarCipher()
// Second function to cipher the text and print it back to the user
{
    string ciphertext = plaintext;
    for (int a = 0; a < strlen(plaintext); a++)
    {
        if (islower(ciphertext[a]))
        {
            ciphertext[a] = ((ciphertext[a] + key - 97) % 26) + 97;
        }
        else if (isupper(ciphertext[a]))
        {
            ciphertext[a] = ((ciphertext[a] + key - 65) % 26) + 65;
        }
        else
        {
            ciphertext[a] = ciphertext[a];
        }
    }
    printf("ciphertext: %s\n", ciphertext);
}