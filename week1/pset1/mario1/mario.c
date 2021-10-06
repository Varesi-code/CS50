#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do 
    {
        //prompts te user for height
       
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
        
        printf("  ");
        
        for (int h = 0; h <= i; h++)
        {
            printf("#");
        }
    
        
        printf("\n");
        
        
        
    }      
    
}