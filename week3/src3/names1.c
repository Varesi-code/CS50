// Implements linear search for names using !

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // An array of names
    string names[] = {"EMMA", "RODRIGO", "BRIAN", "DAVID"};

    // Search for EMMA
    for (int i = 0; i < 4; i++)
    {
        if (!strcmp(names[i], "EMMA")) //string comparison
        {
            printf("Found\n");
            return 0; //returns 0 if two strings are equal
        }
    }
    printf("Not found\n");
    return 1;
}
