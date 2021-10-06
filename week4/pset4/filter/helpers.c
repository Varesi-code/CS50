#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //loops through pixels horizontally
    for (int i = 0; i < height; i++)
    {
        //loops though pixels vertically
        for (int j = 0; j < width; j++)
        {
            //gets existing values
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;

            //calculates average number
            int average = round((blue + green + red) / 3);

            //put average number for all colors
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //loops through pixels horizontally
    for (int i = 0; i < height; i++)
    {
        //loops though pixels vertically
        for (int j = 0; j < width; j++)
        {
            //gets existing values
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;

            //calculates sepia value for red
            int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);

            //checks if value is >= 255
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            //calculates sepia value for blue
            int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);

            //checks if value is >= 255
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }

            //calculates sepia value for green
            int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);

            //checks if value is >=255
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //loop to halfway pixel
    //rows
    for (int i = 0; i < height; i++)
    {
        //columns
        for (int j = 0; j < width / 2; j++)
        {
            //set temporary RGBTRIPLE variable for each pixel
            RGBTRIPLE temp = image[i][j];

            //set current pixel to the reflected one on the other side
            image[i][j] = image[i][width - (j + 1)];

            //reflected pixel set to the original one
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create a temporary array for the blurring loop to occur
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    //iterate though rows and columns to initialise values
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //declare
            float sum_red;
            float sum_green;
            float sum_blue;
            int counter;

            //initialise
            sum_red = sum_green = sum_blue = counter = 0;

            //iterate vertically and horizontally for ech pixel
            for (int m = -1; m < 2; m++)
            {
                for (int n = -1; n < 2; n++)
                {
                    //ckeck rows
                    if (i + m < 0 || i + m >= height)
                    {
                        continue;
                    }

                    //check columns
                    if (j + n < 0 || j + n >= width)
                    {
                        continue;
                    }

                    //otherwise sum
                    sum_red += temp[i + m][j + n].rgbtRed;
                    sum_green += temp[i + m][j + n].rgbtGreen;
                    sum_blue += temp[i + m][j + n].rgbtBlue;
                    counter++;
                }
            }

            //find avg color and set to original array
            image[i][j].rgbtRed = round(sum_red / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtBlue = round(sum_blue / counter);
        }
    }

    return;
}
