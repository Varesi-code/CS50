#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //prompts the user for text
    string text = get_string("Text: ");

    //initializes the counters
    int CountLetters = 0, CountWords = 0, CountSentences = 0;

    //if doesn't start with space, counts 1st word
    if (isalpha(text[0]))
    {
        CountWords++;
    }

    //reads the array checking and adding to counters
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //count letters
        if (isalpha(text[i]))
        {
            CountLetters++;
        }
        //checks for words after " or space in all characters of the string
        if ((isspace(text[i]) || (text[i] == '"')) && isalpha(text[i + 1]))
        {
            CountWords++;
        }
        //checks for punctuation marks to add on to the sentence counter
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            CountSentences++;
        }

    }
    //initializes variables for the coleman liau index
    float L = (float)CountLetters / CountWords * 100;
    float S = (float)CountSentences / (float)CountWords * 100;

    //calculates index value
    float index = 0.0588 * L - 0.296 * S - 15.8;

    //printf("%f\n", index);

    //turns index value into a grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}