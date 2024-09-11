#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;
    int length = strlen (word);
    for (int n = 0; n < length; n++)
    {
        char letter = tolower(word[n]);
        if (letter == 'a' || letter == 'e' ||letter == 'i' ||letter == 'l' ||letter == 'n' ||letter == 'o' ||letter == 'r' ||letter == 's' ||letter == 't' ||letter == 'u')
        {
            score = score + 1;
        } else if (letter == 'd' ||letter == 'g')
        {
            score = score + 2;
        } else if (letter == 'b'|| letter == 'c'|| letter == 'm'|| letter == 'p')
        {
            score = score + 3;
        } else if (letter == 'f'||letter == 'h'|| letter == 'v'|| letter == 'w'||letter == 'y')
        {
            score = score + 4;
        } else if (letter == 'k')
        {
            score = score + 5;
        } else if (letter == 'j'||letter == 'x')
        {
            score = score + 8;
        }else if (letter == 'q'||letter == 'z')
        {
            score = score + 10;
        } else
        {
            score = score + 0;
        }
    }
    return score;
}

