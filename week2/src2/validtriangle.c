#include <cs50.h>
#include <stdio.h>

bool valid_triangle (float a, float b, float c);

int main(void)
{

    float x = get_float("side 1: ");

    float y = get_float("side 2: ");

    float z = get_float("side 3: ");

    float trian = valid_triangle(x, y, z);
}

bool valid_triangle (float a, float b, float c)
{
    float sum = a + b;
    if (sum >= c)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    return true;
}

