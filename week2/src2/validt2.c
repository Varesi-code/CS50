#include <cs50.h>
#include <stdio.h>

bool valid_triangle(float x, float y, float z);

int main(void)
{
    float a = get_float("side 1: ");

    float b = get_float("side 2: ");

    float c = get_float("side 3: ");

    float trian = valid_triangle(a, b, c);
}
bool valid_triangle(float x, float y, float z)
{
    //check for all positive values
    if (x <= 0 || y <= 0 || z <= 0)
    {
        return false;
    }

    //check that sum of any two sides grater than third
    if ((x +y <= z) || (x + z <= y) || (y + z <= x))
    {
        return false;
    }

    //otherwise
    return true;
}