// Prints string char by char, one per line, using strlen

#include <cs50.h>
#include <stdio.h>

//string related functions library
#include <string.h>

int main(void)
{
    string s = get_string("Input:  ");
    printf("Output: ");
    
    //strlen = the lenghth of the string
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
