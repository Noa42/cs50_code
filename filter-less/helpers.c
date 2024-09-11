#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
        {
            for (int j = 0; j <= width; j++)
            {
                int mean = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen)/3.0);
                image[i][j].rgbtBlue = mean;
                image[i][j].rgbtGreen = mean;
                image[i][j].rgbtRed = mean;
            }
        }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int oriR = image[i][j].rgbtRed;
                int oriG = image[i][j].rgbtGreen;
                int oriB = image [i][j].rgbtBlue;
                int newR = round(.393 * oriR + .769 * oriG + .189 * oriB);
                if (newR > 255)
                    {
                        newR = 255;
                    }
                int newG = round(.349 * oriR + .686 * oriG + .168 * oriB);
                 if (newG > 255)
                    {
                        newG = 255;
                    }
                int newB = round(.272 * oriR + .534 * oriG + .131 * oriB);
                if (newG > 255)
                    {
                        newG = 255;
                    }
                image[i][j].rgbtRed = newR;
                image[i][j].rgbtGreen = newG;
                image[i][j].rgbtBlue = newB;
            }
        }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
                {
                    copy[i][j] = image[i][j];
                }
        }
    for (int i = 0; i < height; i++)
        {
            for (int j = 0, z = width-1; j < width; j++, z--)
                {
                    image[i][j] = copy[i][z];
                }
        }
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int meanR;
    int meanG;
    int meanB;
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
        {
            for (int j= 0; j < width; j++)
                {
                    copy[i][j] = image[i][j];
                }
        }
    for (int i = 1; i < height-1; i++)
        {
            for (int j = 1; j < width-1; j++)
                {
                    meanR = round((copy[i-1][j-1].rgbtRed + copy[i-1][j].rgbtRed + copy[i-1][j+1].rgbtRed + copy[i][j-1].rgbtRed + copy[i][j].rgbtRed + copy[i][j+1].rgbtRed + copy[i+1][j-1].rgbtRed + copy[i+1][j].rgbtRed + copy[i+1][j+1].rgbtRed)/9.0);
                    meanG = round((copy[i-1][j-1].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i-1][j+1].rgbtGreen + copy[i][j-1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j+1].rgbtGreen + copy[i+1][j-1].rgbtGreen + copy[i+1][j].rgbtGreen + copy[i+1][j+1].rgbtGreen)/9.0);
                    meanB = round((copy[i-1][j-1].rgbtBlue + copy[i-1][j].rgbtBlue + copy[i-1][j+1].rgbtBlue + copy[i][j-1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j+1].rgbtBlue + copy[i+1][j-1].rgbtBlue + copy[i+1][j].rgbtBlue + copy[i+1][j+1].rgbtBlue)/9.0);
                    image[i][j].rgbtRed = meanR;
                    image[i][j].rgbtGreen = meanG;
                    image[i][j].rgbtBlue = meanB;
                }
        }
    // La primera linea i=0 y j=1 hasta
    for (int j = 1; j < width-1; j++)
        {
            meanR = round((copy[0][j-1].rgbtRed + copy[0][j].rgbtRed + copy[0][j+1].rgbtRed + copy[1][j-1].rgbtRed + copy[1][j].rgbtRed + copy[1][j+1].rgbtRed)/6.0);
            meanG = round((copy[0][j-1].rgbtGreen + copy[0][j].rgbtGreen + copy[0][j+1].rgbtGreen + copy[1][j-1].rgbtGreen + copy[1][j].rgbtGreen + copy[1][j+1].rgbtGreen)/6.0);
            meanB = round((copy[0][j-1].rgbtBlue + copy[0][j].rgbtBlue + copy[0][j+1].rgbtBlue + copy[1][j-1].rgbtBlue + copy[1][j].rgbtBlue + copy[1][j+1].rgbtBlue)/6.0);
            image[0][j].rgbtRed = meanR;
            image[0][j].rgbtGreen = meanG;
            image[0][j].rgbtBlue = meanB;
        }
        // La ultima linea i=height y j=1 hasta
    for (int j = 1; j < width-1; j++)
        {
            meanR = round((copy[height-1][j-1].rgbtRed + copy[height-1][j].rgbtRed + copy[height-1][j+1].rgbtRed + copy[height][j-1].rgbtRed + copy[height][j].rgbtRed + copy[height][j+1].rgbtRed)/6.0);
            meanG = round((copy[height-1][j-1].rgbtGreen + copy[height-1][j].rgbtGreen + copy[height-1][j+1].rgbtGreen + copy[height][j-1].rgbtGreen + copy[height][j].rgbtGreen + copy[height][j+1].rgbtGreen)/6.0);
            meanB = round((copy[height-1][j-1].rgbtBlue + copy[height-1][j].rgbtBlue + copy[height-1][j+1].rgbtBlue + copy[height][j-1].rgbtBlue + copy[height][j].rgbtBlue + copy[height][j+1].rgbtBlue)/6.0);
            image[height][j].rgbtRed = meanR;
            image[height][j].rgbtGreen = meanG;
            image[height][j].rgbtBlue = meanB;
        }
        //La primera columna j 0
        for (int i = 1; i < height-1; i++)
            {
            meanR = round((copy[i-1][0].rgbtRed + copy[i-1][1].rgbtRed + copy[i][0].rgbtRed + copy[i][1].rgbtRed + copy[i+1][0].rgbtRed + copy[i+1][1].rgbtRed)/6.0);
            meanG = round((copy[i-1][0].rgbtGreen + copy[i-1][1].rgbtGreen + copy[i][0].rgbtGreen + copy[i][1].rgbtGreen + copy[i+1][0].rgbtGreen + copy[i+1][1].rgbtGreen)/6.0);
            meanB = round((copy[i-1][0].rgbtBlue + copy[i-1][1].rgbtBlue + copy[i][0].rgbtBlue + copy[i][1].rgbtBlue + copy[i+1][0].rgbtBlue + copy[i+1][1].rgbtBlue)/6.0);
            image[i][0].rgbtRed = meanR;
            image[i][0].rgbtGreen = meanG;
            image[i][0].rgbtBlue = meanB;
            }
        //La ultima columna j=width
        for (int i = 1; i < height-1; i++)
            {
            meanR = round((copy[i-1][height-1].rgbtRed + copy[i-1][height].rgbtRed + copy[i][height-1].rgbtRed + copy[i][height].rgbtRed + copy[i+1][height-1].rgbtRed + copy[i+1][height].rgbtRed)/6.0);
            meanG = round((copy[i-1][height-1].rgbtGreen + copy[i-1][height].rgbtGreen + copy[i][height-1].rgbtGreen + copy[i][height].rgbtGreen + copy[i+1][height-1].rgbtGreen + copy[i+1][height].rgbtGreen)/6.0);
            meanB = round((copy[i-1][height-1].rgbtBlue + copy[i-1][height].rgbtBlue + copy[i][height-1].rgbtBlue + copy[i][height].rgbtBlue + copy[i+1][height-1].rgbtBlue + copy[i+1][height].rgbtBlue)/6.0);
            image[i][width].rgbtRed = meanR;
            image[i][width].rgbtGreen = meanG;
            image[i][width].rgbtBlue = meanB;
            }
        //La esquina superiror izquierda
        meanR = round((copy[0][0].rgbtRed + copy[0][1].rgbtRed + copy[1][0].rgbtRed + copy[1][1].rgbtRed)/4.0);
        meanG = round((copy[0][0].rgbtGreen + copy[0][1].rgbtGreen + copy[1][0].rgbtGreen + copy[1][1].rgbtGreen)/4.0);
        meanB = round((copy[0][0].rgbtBlue + copy[0][1].rgbtBlue + copy[1][0].rgbtBlue + copy[1][1].rgbtBlue)/4.0);
        image[0][0].rgbtRed = meanR;
        image[0][0].rgbtGreen = meanG;
        image[0][0].rgbtBlue = meanB;
        //La esquina superior derecha
        meanR = round((copy[0][width-1].rgbtRed + copy[0][width].rgbtRed + copy[1][width-1].rgbtRed + copy[1][width].rgbtRed)/4.0);
        meanG = round((copy[0][width-1].rgbtGreen + copy[0][width].rgbtGreen + copy[1][width-1].rgbtGreen + copy[1][width].rgbtGreen)/4.0);
        meanB = round((copy[0][width-1].rgbtBlue + copy[0][width].rgbtBlue + copy[1][width-1].rgbtBlue + copy[1][width].rgbtBlue)/4.0);
        image[0][width].rgbtRed = meanR;
        image[0][width].rgbtGreen = meanG;
        image[0][width].rgbtBlue = meanB;
        //La esquina inferior izquierda
        meanR = round((copy[height-1][0].rgbtRed + copy[height-1][1].rgbtRed + copy[height][0].rgbtRed + copy[height][1].rgbtRed)/4.0);
        meanG = round((copy[height-1][0].rgbtGreen + copy[height-1][1].rgbtGreen + copy[height][0].rgbtGreen + copy[height][1].rgbtGreen)/4.0);
        meanB = round((copy[height-1][0].rgbtBlue + copy[height-1][1].rgbtBlue + copy[height][0].rgbtBlue + copy[height][1].rgbtBlue)/4.0);
        image[height][0].rgbtRed = meanR;
        image[height][0].rgbtGreen = meanG;
        image[height][0].rgbtBlue = meanB;
        //La esquina inferior derecha
        meanR = round((copy[height-1][width-1].rgbtRed + copy[height-1][width].rgbtRed + copy[height][width-1].rgbtRed + copy[height][width].rgbtRed)/4.0);
        meanG = round((copy[height-1][width-1].rgbtGreen + copy[height-1][width].rgbtGreen + copy[height][width-1].rgbtGreen + copy[height][width].rgbtGreen)/4.0);
        meanB = round((copy[height-1][width-1].rgbtGreen + copy[height-1][width].rgbtGreen + copy[height][width-1].rgbtGreen + copy[height][width].rgbtGreen)/4.0);
        image[height][width].rgbtRed = meanR;
        image[height][width].rgbtGreen = meanG;
        image[height][width].rgbtBlue = meanB;
    return;
}
