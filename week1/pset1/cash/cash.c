#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int pennie = 1;
    //amount of coins ie times that ops turns true
    int coins = 0;
    
    //prompt user for amount of change in floating numbers
    float ChangeD;
    do
    {
        ChangeD = get_float("Change owed: ");
    }
    while (ChangeD <= 0);
    
    //convert change in dollars to change in cents to avoid imprecision
    int ChangeC = round(ChangeD * 100);
    
     
    while (ChangeC > 0)
    {
        //chack quarters
        if (ChangeC >= quarter)
        {
            ChangeC = ChangeC - quarter;
        }
        //check dimes
        else if (ChangeC >= dime)
        {
            
            ChangeC = ChangeC - dime;
        }
        //check nickels
        else if (ChangeC >= nickel)
        {
            
            ChangeC = ChangeC - nickel;
        }
        //check pennies
        else if (ChangeC >= pennie)
        {
            
            ChangeC = ChangeC - pennie;
        }
        
        coins++;
        
    }
    
    /*
    while (ChangeC >= quarter)
    {
        coins++;
        ChangeC = ChangeC - quarter;
    }
    
    
    while (ChangeC >= dime)
    {
        coins++;
        ChangeC = ChangeC - dime;
    }
    
    while (ChangeC >= nickel)
    {
        coins++;
        ChangeC = ChangeC - nickel;
    }
    
    while (ChangeC >= pennie)
    {
        coins++;
        ChangeC = ChangeC - pennie;
    }
    */
    
    printf("%i\n", coins);
    
}