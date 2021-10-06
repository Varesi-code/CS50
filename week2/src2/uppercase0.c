// Uppercases a string

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //if it's a lowercase letter
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            //print uppercase
            printf("%c", s[i] - 32);
        }
        //else leave it alone
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
