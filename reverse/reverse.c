#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        return 1;
    }
    char* name_input = argv[1];
    char* name_output = argv [2];

    // Open input file for reading
    // TODO #2
   FILE* pread = fopen(name_input, "r");//falta el fclose
   if (pread == NULL)
    {
        return 1;
    }

    // Read header into an array
    // TODO #3
    WAVHEADER cabecero;
    fread(&cabecero, sizeof(WAVHEADER), 1, pread);

    // Use check_format to ensure WAV format
    // TODO #4

    if (check_format(cabecero) == 1)
        {
            printf("Wrong format");
            return 1;
        } else
            {
                printf("Right format\n");
            }

    // Open output file for writing
    // TODO #5
    FILE* pwrite = fopen(name_output, "w");//falta el fclose
   if (pwrite == NULL)
    {
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite (&cabecero, sizeof(WAVHEADER), 1, pwrite);

    // Use get_block_size to calculate size of block
    // TODO #7
    int blocksize = get_block_size(cabecero);

    // Write reversed audio to file
    // TODO #8
    FILE* pcount = fopen(name_input, "r");
    WAVHEADER basura;
    fread(&basura, sizeof(WAVHEADER), 1, pread);
    int numchar = 0;
    char x;
    while((x = fgetc(pcount)) != EOF)
        {
            numchar++;
        }
   long ult = ftell(pcount);
    printf ("Numchar es %i y la ùltima posición es %li\n", numchar, ult);
    long numblocks = numchar/blocksize; //numchar es 3816 y blocksize es 4
    printf ("Numblocks es %li\n", numblocks);
    BYTE block;
    fseek(pread, -blocksize*(sizeof(BYTE)), SEEK_END); //mueve el pread al principio del primer bloque que queremos leer
    int iteracion = 0;
    for (iteracion = 0; iteracion < numblocks; iteracion++)
        {
            fread(&block, sizeof(BYTE), blocksize, pread); //primero lo lee en el array block
            fseek(pread, -2*blocksize*sizeof(BYTE), SEEK_CUR); //Retrocede dos bloques(es decir al principio del bloque anterior porque el surso se ha quedar en el final del bolque actual)
            fwrite(&block, sizeof(BYTE) , blocksize, pwrite); //Escribe el bloque que acaba de leer en el documento de salida
            //printf("%i\n", i);
            //printf("++++++++++%i\n", block);
        }
    printf("El número de iteraciones es: %i\n", iteracion);
    //Cierre de archivos
    fclose(pread);
    fclose(pwrite);
    fclose (pcount);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    char* format = malloc(4*sizeof(char));
    for (int i = 0; i < 4 ; i++)
        {
            format [i] = header.format[i];
        }
    if (strcmp(format, "WAVE") == 0)
        {
            return 0;
        } else
            {
                 return 1;
            }
    free(format);
}

int get_block_size(WAVHEADER header)
{
    // TODO #7 number of channels multiplied by bytes per sample.
    int size = header.numChannels*(header.bitsPerSample/8);
    printf("Size is: %i\nNumChannels is: %i, Bitspersample is: %i \n", size, header.numChannels, header.bitsPerSample);
    return size;
}