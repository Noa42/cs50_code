// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <strings.h>
#include <stdio.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1214; //26 + 27 * 44 (ninguna palabra empieza por apostrofe)

// Hash table
node *table[N];

//Mis variables globales
unsigned int tam = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    node* cursor = table[hash(word)]; // dudo si aqui tengo que poner el asterico
    char copy[strlen(word)];
    strcpy(copy, word);
    while(cursor != NULL)
    {
        if (strcasecmp(copy, cursor->word) == 0)
            return true;
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int index = 0;
    for(int i = 0; i < strlen(word) ; i++)
    {
        if (word[i] == 39)
            index = index + 27;
        else
            index = index + toupper(word[i]) - 'A';
    }
    if (index > N)
        index = index % N;
    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char word[LENGTH + 1];
    int index;
    FILE *read = fopen(dictionary, "r");
    if(read == NULL)
        return false;
    else
    {
        while(fscanf(read, "%s", word) != EOF)
        {
            node* new = malloc(sizeof(node));
            if(new == NULL)
                return false;
            else
            {
                tam ++;
                strcpy(new->word, word);
                index = hash(word);
                new->next = table[index];
                table[index] = new;
                //printf("---%s indice: %i", new->word, index);
            }
        }
    }
    fclose(read);
    return true;
}
// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return tam;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node* cursor;
    node* temp;
    for (unsigned int i = 0; i < N; i++)
    {
        cursor = table[i];
        while(cursor != NULL)
        {
            temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
