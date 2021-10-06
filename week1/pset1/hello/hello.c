#include <stdio.h>
#include <cs50.h>

int main(void)
{
    
    // prompts user for name
    string name = get_string("What's your name?\n");
    
    //prints user input
    printf("Hello,%s\n", name);
}