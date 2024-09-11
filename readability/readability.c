#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//Prototypes
int count_letters(string text);
int count_words (string text);
int count_sentences (string text);

int main(void)
{
string text = get_string ("Text: ");
float letters = count_letters (text);
float words = count_words (text);
float sentences = count_sentences (text);
float l, s;
l = (letters*100)/(words);
s = (sentences*100)/(words);
int index = round ((0.0588*l)-(0.296*s)-15.8);
if (index < 1)
{
        printf("Before Grade 1\n");
} else if (index > 16)
{
    printf("Grade 16+\n");
} else
{
printf("Grade %i\n", index);
}

}

//Functions

int count_letters(string text)
{
    int letters = 0;
    int total = strlen (text);
    for (int i = 0; i <= total; i++)
    {
        char pointer = text [i];
        int ascii = pointer;
        if ((ascii >= 65 && ascii<= 90)||(ascii >= 97 && ascii <= 122))
        {
            letters ++;
        }
    }
        return letters;
}

int count_words (string text)
{
    int words = 1;
    int total = strlen (text);
    for (int i = 0; i <= total; i++)
    {
        char pointer = text [i];
        int ascii = pointer;
        if (ascii == 32)
        {
            words ++;
        }
    }
    return words;
}

int count_sentences (string text)
{
    int sent = 0;
    int total = strlen (text);
    for (int i = 0; i <= total; i++)
    {
        char pointer = text [i];
        int ascii = pointer;
        if (ascii == 46 || ascii == 63 || ascii == 33)
        {
            sent ++;
        }
    }
    return sent;
}