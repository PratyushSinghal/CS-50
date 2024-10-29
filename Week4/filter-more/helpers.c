#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumred = 0;
            int sumgreen = 0;
            int sumblue = 0;
            int counter = 0;
            for (int updatei = i - 1; updatei < i + 2; updatei++)
            {
                for (int updatej = j - 1; updatej < j + 2; updatej++)
                {
                    if ((updatei >= 0 && updatej >= 0) && (updatei < height && updatej < width))
                    {
                        sumred += image[updatei][updatej].rgbtRed;
                        sumgreen += image[updatei][updatej].rgbtGreen;
                        sumblue += image[updatei][updatej].rgbtBlue;
                        counter++;
                    }
                }
            }
            copy[i][j].rgbtRed = round(sumred / (float) counter);
            copy[i][j].rgbtGreen = round(sumgreen / (float) counter);
            copy[i][j].rgbtBlue = round(sumblue / (float) counter);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int gx_array[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int gy_array[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gx_red = 0;
            int gx_green = 0;
            int gx_blue = 0;
            int gy_red = 0;
            int gy_green = 0;
            int gy_blue = 0;
            int counter = 0;
            for (int updatei = i - 1; updatei < i + 2; updatei++)
            {
                for (int updatej = j - 1; updatej < j + 2; updatej++)
                {
                    if ((updatei >= 0 && updatej >= 0) && (updatei < height && updatej < width))
                    {
                        gx_red = gx_red + gx_array[counter] * image[updatei][updatej].rgbtRed;
                        gx_green = gx_green + gx_array[counter] * image[updatei][updatej].rgbtGreen;
                        gx_blue = gx_blue + gx_array[counter] * image[updatei][updatej].rgbtBlue;
                        gy_red = gy_red + gy_array[counter] * image[updatei][updatej].rgbtRed;
                        gy_green = gy_green + gy_array[counter] * image[updatei][updatej].rgbtGreen;
                        gy_blue = gy_blue + gy_array[counter] * image[updatei][updatej].rgbtBlue;
                    }
                    counter++;
                }
            }
            int final_red = round(sqrt(pow(gx_red, 2) + pow(gy_red, 2)));
            int final_green = round(sqrt(pow(gx_green, 2) + pow(gy_green, 2)));
            int final_blue = round(sqrt(pow(gx_blue, 2) + pow(gy_blue, 2)));

            if (final_red > 255)
            {
                final_red = 255;
            }
            else if (final_green > 255)
            {
                final_green = 255;
            }
            else if (final_blue > 255)
            {
                final_blue = 255;
            }

            copy[i][j].rgbtRed = final_red;
            copy[i][j].rgbtGreen = final_green;
            copy[i][j].rgbtBlue = final_blue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
