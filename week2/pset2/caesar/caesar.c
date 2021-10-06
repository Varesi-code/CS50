#include <cs50.h> //contains get_string
#include <stdio.h>
#include <string.h> //contains strlen
#include <ctype.h> //contains isdigit isalpha etc
#include <stdlib.h> //contains atoi

int main(int argc, string argv[])
{
    //checks command-line arg to be size 2
    if (argc != 2)
    {
        printf("./caesar key\n");
        return 1;
    }
    else
    {
        //checks clang to be a number along its length
        for (int i = 0, j = strlen(argv[1]); i < j; i++)
        {
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    //turns command-line arg into an int
    int key = atoi(argv[1]);
    //test command-line arg correct
    //printf("%i\n", i);

    //asks user for text to be encrypted
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    //checks string char per char for:
    for (int g = 0, h = strlen(plaintext); g < h; g++)
    {
        //alpha char class
        if (isalpha(plaintext[g]))
        {
            //uppercase char
            if (isupper(plaintext[g]))
            {
                printf("%c", ((((plaintext[g] - 65) + key) % 26) + 65));
            }
            //lowercase char
            if (islower(plaintext[g]))
            {
                printf("%c", ((((plaintext[g] - 97) + key) % 26) + 97));
            }
        }
        else
        {
            //leaves non alpha char class as they are
            printf("%c", plaintext[g]);
        }
    }
    //prints a line break
    printf("\n");
    return 0;
}