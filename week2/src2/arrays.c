#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int numbers[100];
    int k = 100;

    for (int j=0; j < k; j++)
    {
        numbers[j] = j + 1;

        //print name
        printf("array number:%i\n", j);

        //print value of name
        printf("value:%i\n", numbers[j]);
    }

}