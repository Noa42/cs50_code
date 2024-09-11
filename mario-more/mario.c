#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cont = 1;
    int i;
    int h = get_int("We are going to create a pyramide for you. What will be the height? (from 1 to 8): ");
    while (h < 1 || h > 8)
    {
        h = get_int ("We are going to create a pyramide for you. What will be the height? (from 1 to 8): ");
    }

    while (h > 0)
        {
        for (int j = h - 1; j > 0; j--)
            {
            printf(" ");
            }
        for (i = 1; i <= cont; i++)
            {
                printf("#");
            }
        printf("  ");
        for (i = 1; i <= cont; i++)
            {
                printf("#");
            }
        cont ++;
        h--;
        printf("\n");
        }

}