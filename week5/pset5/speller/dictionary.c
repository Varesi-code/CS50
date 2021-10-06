// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// initialise global variables

//represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;
// number of buckets in hash table (one for each one of the letters of the alphabet)
const unsigned int N = 26;
//positive hash value
unsigned int hashValue;
// initialise (positive) hash table
unsigned int wordCount;

node *hash_table[N];

// Loads dict into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dict
    FILE *file = fopen(dictionary, "r");
    // If file is not opened, return false
    if (file != NULL)
    {
        // storage space for word
        char word[LENGTH + 1];
        // Scan dict for strings that are not the end of the file
        while (fscanf(file, "%s", word) != EOF)
        {
            // Allocate memory for new node
            node *n = malloc(sizeof(node));
            // If malloc returns NULL, return false
            if (n == NULL)
            {
                return false;
            }
            // Pointer to next node and word itself
            strcpy(n->word, word);

            // Hash the word to get hash value
            hashValue = hash(word);
            // Set new pointer
            n->next = hash_table[hashValue];
            // Set head to new pointer
            hash_table[hashValue] = n;
            // Increment word count
            wordCount++;
        }
        // Close file
        fclose(file);
        // If dict is loaded, return true
        return true;
    }
    else
    {
        return false;
    }
}

// Hashes word to a number
// From djib2 by Dan Bernstein (http://www.cse.yorku.ca/~oz/hash.html)

unsigned int hash(const char *word)

{

    unsigned long hash = 5381;

    int c = *word;

    c = tolower(c);

    while (*word != 0)

    {

        hash = ((hash << 5) + hash) + c;

        c = *word++;

        c = tolower(c);

    }

    return hash % N;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Check if there aren't any words in wordCount (coming from load func)
    if (wordCount <= 0)
    {
        return 0;
    }
    else
    {
        // Show count if there are
        return wordCount;
    }
}

//Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //hash the word to get number
    hashValue = hash(word);
    //access the list
    node *pointer = hash_table[hashValue];
    //search in the linked list
    while (pointer != NULL)
    {
        //check if the word matches
        if (strcasecmp(word, pointer->word) == 0)
        {
            return true;
        }
        else
        {
            //move pointer to next node
            pointer = pointer->next;
        }
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // loop through buckets
    for (int i = 0; i < N; i++)
    {
        // Set pointer to each bucket
        node *pointer = hash_table[i];
        // free null pointers
        while (pointer)
        {
            // Create temp
            node *tmp = pointer;
            // Move pointer to next node
            pointer = pointer->next;
            // Free up temp
            free(tmp);
        }
        // If pointer is NULL
        if (i == N - 1 && pointer == NULL)
        {
            return true;
        }
    }
    return false;
}