#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    } else {

        for (int n = 0; n < strlen(argv[1]); n++)
        {
            if (argv[1][n] < 48 || argv[1][n] > 57)
            {
            printf("Usage: ./caesar key\n");
            return 1;
            }
        }
    }
    int input = (int) strtol(argv[1], NULL, 10);
    int key = input%26;
    string plain = get_string("plaintext: ");
    int length = strlen(plain);
    printf ("lenght: %i\n", length);
    char cipher [length+80];
    printf ("\n");
    for (int n = 0; n < length; n++)
        {
            if ((plain [n] >= 65 && plain [n] <= 90) || (plain [n] >= 97 && plain [n] <= 122))
            {
                cipher[n] = plain[n] + key;
                if ((plain [n] >= 97 && plain [n] <= 122 && cipher [n] > 122) || (plain [n] >= 65 && plain [n] <= 90 && cipher [n] > 90))
                {
                        cipher[n] = cipher[n] - 26;
                }

            }
            else
             {
                cipher[n] = plain[n];
             }
        }

printf ("ciphertext: %s\n", cipher);
return 0;
}
//printf("plaint: %i, plainchar: %c\n ciint: %i, cichar: %c\nKey: %i\n", plain[n], plain[n], cipher[n], cipher[n], key);