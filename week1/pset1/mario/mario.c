#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do 
    {
        //prompts user for height
       
        n = get_int("Height: ");
    }
    //asks recursively until parameters are correct
    while (n < 1 || n > 8);
    
    //criteria for printing the pyramid
    //creates a variable according to which two options can be developed
    for (int i = 0; i < n; i++)
    {
        //" " is printed
        for (int p = n - 1; p > i; p--)
        {
            printf(" ");
        }
        
        //"#" is printed
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        
        printf("\n");
    }
    /*
    ........#   8   1
    .......##   7   2
    ......###   6   3
    .....####   5   4
    ....#####   4   5   
    ...######   3   6   
    ..#######   2   7
    .########   1   8 
    */
    
}