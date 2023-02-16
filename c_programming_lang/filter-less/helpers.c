#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // int x will be the variable that holds the average of all three color values
    int x;
    // iterate through the 2d array
    for (int i = 0; i < (height); i++)
    {
        for (int j = 0; j < (width); j++)
        {
            // for each pixel - calculate the average of the colors
            x = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            // set the average equal to each pixel color to create a greyscale
            image[i][j].rgbtRed = x;
            image[i][j].rgbtGreen = x;
            image[i][j].rgbtBlue = x;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate through the 2D array to perform code on each pixel
    for (int i = 0; i < (height); i++)
    {
        for (int j = 0; j < (width); j++)
        {
            // for each pixel - calculate the sepia value using the formula provided by cs50. Round it so whole number only.
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            // need to make sure the value is never greater than 255, so if greater, setting equal to 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            // updating each pixel color to their respective sepia values.
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // create a rgbtriple to hold temporary values to allow for swapping. Allocate memory that is the size of the image
    // if not enough memory available - print message
    RGBTRIPLE(*temp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (temp == NULL)
    {
        printf("Not enough memory to store image.\n");
    }
    // create a variable that will account for the image from the right side of each row (width).
    int x = (width - 1);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= ((round(width / 2)) - 1); j++)
        {
            temp[i][j].rgbtRed = image[i][j].rgbtRed;
            temp[i][j].rgbtGreen = image[i][j].rgbtGreen;
            temp[i][j].rgbtBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][x].rgbtRed;
            image[i][j].rgbtGreen = image[i][x].rgbtGreen;
            image[i][j].rgbtBlue = image[i][x].rgbtBlue;
            image[i][x].rgbtRed = temp[i][j].rgbtRed;
            image[i][x].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][x].rgbtBlue = temp[i][j].rgbtBlue;
            if (x > (width / 2))
            {
                x--;
            }
        }
        x = (width - 1);
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*copy)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (copy == NULL)
    {
        printf("Not enough memory to store image.\n");
    }
    for (int i = 0; i < (height); i++)
    {
        for (int j = 0; j < (width); j++)
        {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    float addRed = 0;
    float addGreen = 0;
    float addBlue = 0;
    for (int i = 0; i < (height); i++)
    {
        for (int j = 0; j < (width); j++)
        {
            if (i == 0  && j == 0)
            {
                addBlue = (copy[i][j].rgbtBlue +
                copy[i][j + 1].rgbtBlue +
                copy[i + 1][j + 1].rgbtBlue +
                copy[i + 1][j].rgbtBlue);
                addGreen = (copy[i][j].rgbtGreen +
                copy[i][j + 1].rgbtGreen +
                copy[i + 1][j + 1].rgbtGreen +
                copy[i + 1][j].rgbtGreen);
                addRed = (copy[i][j].rgbtRed +
                copy[i][j + 1].rgbtRed +
                copy[i + 1][j + 1].rgbtRed +
                copy[i + 1][j].rgbtRed);
                image[i][j].rgbtRed = round(addRed / 4);
                image[i][j].rgbtGreen = round(addGreen / 4);
                image[i][j].rgbtBlue = round(addBlue / 4);
            }
            else if (i == 0 && j == (width - 1))
            {
                addBlue = (copy[i][j].rgbtBlue +
                copy[i][j - 1].rgbtBlue +
                copy[i + 1][j - 1].rgbtBlue +
                copy[i + 1][j].rgbtBlue);
                addGreen = (copy[i][j].rgbtGreen +
                copy[i][j - 1].rgbtGreen +
                copy[i + 1][j - 1].rgbtGreen +
                copy[i + 1][j].rgbtGreen);
                addRed = (copy[i][j].rgbtRed +
                copy[i][j - 1].rgbtRed +
                copy[i + 1][j - 1].rgbtRed +
                copy[i + 1][j].rgbtRed);
                image[i][j].rgbtRed = round(addRed / 4);
                image[i][j].rgbtGreen = round(addGreen / 4);
                image[i][j].rgbtBlue = round(addBlue / 4);
            }
            else if (i == (height - 1) && j == 0)
            {
                addBlue = (copy[i][j].rgbtBlue +
                copy[i][j + 1].rgbtBlue +
                copy[i - 1][j + 1].rgbtBlue +
                copy[i - 1][j].rgbtBlue);
                addGreen = (copy[i][j].rgbtGreen +
                copy[i][j + 1].rgbtGreen +
                copy[i - 1][j + 1].rgbtGreen +
                copy[i - 1][j].rgbtGreen);
                addRed = (copy[i][j].rgbtRed +
                copy[i][j + 1].rgbtRed +
                copy[i - 1][j + 1].rgbtRed +
                copy[i - 1][j].rgbtRed);
                image[i][j].rgbtRed = round(addRed / 4);
                image[i][j].rgbtGreen = round(addGreen / 4);
                image[i][j].rgbtBlue = round(addBlue / 4);
            }
            else if (i == (height - 1) && j == (width - 1))
            {
                addBlue = (copy[i][j].rgbtBlue +
                copy[i][j - 1].rgbtBlue +
                copy[i - 1][j - 1].rgbtBlue +
                copy[i - 1][j].rgbtBlue);
                addGreen = (copy[i][j].rgbtGreen +
                copy[i][j - 1].rgbtGreen +
                copy[i - 1][j - 1].rgbtGreen +
                copy[i - 1][j].rgbtGreen);
                addRed = (copy[i][j].rgbtRed +
                copy[i][j - 1].rgbtRed +
                copy[i - 1][j - 1].rgbtRed +
                copy[i - 1][j].rgbtRed);
                image[i][j].rgbtRed = round(addRed / 4);
                image[i][j].rgbtGreen = round(addGreen / 4);
                image[i][j].rgbtBlue = round(addBlue / 4);
            }
            else if ((i == 0  && j != 0) || (i == 0 && j != (width - 1)))
            {
                addBlue = (copy[i][j].rgbtBlue +
                copy[i][j + 1].rgbtBlue +
                copy[i][j - 1].rgbtBlue +
                copy[i + 1][j - 1].rgbtBlue +
                copy[i + 1][j + 1].rgbtBlue +
                copy[i + 1][j].rgbtBlue);
                addGreen = (copy[i][j].rgbtGreen +
                copy[i][j + 1].rgbtGreen +
                copy[i][j - 1].rgbtGreen +
                copy[i + 1][j + 1].rgbtGreen +
                copy[i + 1][j - 1].rgbtGreen +
                copy[i + 1][j].rgbtGreen);
                addRed = (copy[i][j].rgbtRed +
                copy[i][j + 1].rgbtRed +
                copy[i][j - 1].rgbtRed +
                copy[i + 1][j + 1].rgbtRed +
                copy[i + 1][j - 1].rgbtRed +
                copy[i + 1][j].rgbtRed);
                image[i][j].rgbtRed = round(addRed / 6);
                image[i][j].rgbtGreen = round(addGreen / 6);
                image[i][j].rgbtBlue = round(addBlue / 6);
            }
            else if ((i != 0  && j == 0) || (i != (height - 1) && j == 0))
            {
                addBlue = (copy[i][j].rgbtBlue +
                copy[i][j + 1].rgbtBlue +
                copy[i - 1][j].rgbtBlue +
                copy[i - 1][j + 1].rgbtBlue +
                copy[i + 1][j + 1].rgbtBlue +
                copy[i + 1][j].rgbtBlue);
                addGreen = (copy[i][j].rgbtGreen +
                copy[i][j + 1].rgbtGreen +
                copy[i - 1][j].rgbtGreen +
                copy[i - 1][j + 1].rgbtGreen +
                copy[i + 1][j + 1].rgbtGreen +
                copy[i + 1][j].rgbtGreen);
                addRed = (copy[i][j].rgbtRed +
                copy[i][j + 1].rgbtRed +
                copy[i - 1][j].rgbtRed +
                copy[i - 1][j + 1].rgbtRed +
                copy[i + 1][j + 1].rgbtRed +
                copy[i + 1][j].rgbtRed);
                image[i][j].rgbtRed = round(addRed / 6);
                image[i][j].rgbtGreen = round(addGreen / 6);
                image[i][j].rgbtBlue = round(addBlue / 6);
            }
            else if ((i != 0  && j == (width - 1)) || (i != (height - 1) && j == (width - 1)))
            {
                addBlue = (copy[i][j].rgbtBlue +
                copy[i][j - 1].rgbtBlue +
                copy[i - 1][j].rgbtBlue +
                copy[i - 1][j - 1].rgbtBlue +
                copy[i + 1][j - 1].rgbtBlue +
                copy[i + 1][j].rgbtBlue);
                addGreen = (copy[i][j].rgbtGreen +
                copy[i][j - 1].rgbtGreen +
                copy[i - 1][j].rgbtGreen +
                copy[i - 1][j - 1].rgbtGreen +
                copy[i + 1][j - 1].rgbtGreen +
                copy[i + 1][j].rgbtGreen);
                addRed = (copy[i][j].rgbtRed +
                copy[i][j - 1].rgbtRed +
                copy[i - 1][j].rgbtRed +
                copy[i - 1][j - 1].rgbtRed +
                copy[i + 1][j - 1].rgbtRed +
                copy[i + 1][j].rgbtRed);
                image[i][j].rgbtRed = round(addRed / 6);
                image[i][j].rgbtGreen = round(addGreen / 6);
                image[i][j].rgbtBlue = round(addBlue / 6);
            }
            else if ((i == (height - 1)  && j != 0) || (i == (height - 1) && j != (width - 1)))
            {
                addBlue = (copy[i][j].rgbtBlue +
                copy[i][j + 1].rgbtBlue +
                copy[i][j - 1].rgbtBlue +
                copy[i - 1][j - 1].rgbtBlue +
                copy[i - 1][j + 1].rgbtBlue +
                copy[i - 1][j].rgbtBlue);
                addGreen = (copy[i][j].rgbtGreen +
                copy[i][j + 1].rgbtGreen +
                copy[i][j - 1].rgbtGreen +
                copy[i - 1][j + 1].rgbtGreen +
                copy[i - 1][j - 1].rgbtGreen +
                copy[i - 1][j].rgbtGreen);
                addRed = (copy[i][j].rgbtRed +
                copy[i][j + 1].rgbtRed +
                copy[i][j - 1].rgbtRed +
                copy[i - 1][j + 1].rgbtRed +
                copy[i - 1][j - 1].rgbtRed +
                copy[i - 1][j].rgbtRed);
                image[i][j].rgbtRed = round(addRed / 6);
                image[i][j].rgbtGreen = round(addGreen / 6);
                image[i][j].rgbtBlue = round(addBlue / 6);
            }
            else
            {
                addRed = (copy[i][j].rgbtRed +
                copy[i - 1][j - 1].rgbtRed +
                copy[i - 1][j].rgbtRed +
                copy[i - 1][j + 1].rgbtRed +
                copy[i][j - 1].rgbtRed +
                copy[i][j + 1].rgbtRed +
                copy[i + 1][j - 1].rgbtRed +
                copy[i + 1][j].rgbtRed +
                copy[i + 1][j + 1].rgbtRed);
                addGreen = (copy[i][j].rgbtGreen +
                copy[i - 1][j - 1].rgbtGreen +
                copy[i - 1][j].rgbtGreen +
                copy[i - 1][j + 1].rgbtGreen +
                copy[i][j - 1].rgbtGreen +
                copy[i][j + 1].rgbtGreen +
                copy[i + 1][j - 1].rgbtGreen +
                copy[i + 1][j].rgbtGreen +
                copy[i + 1][j + 1].rgbtGreen);
                addBlue = (copy[i][j].rgbtBlue +
                copy[i - 1][j - 1].rgbtBlue +
                copy[i - 1][j].rgbtBlue +
                copy[i - 1][j + 1].rgbtBlue +
                copy[i][j - 1].rgbtBlue +
                copy[i][j + 1].rgbtBlue +
                copy[i + 1][j - 1].rgbtBlue +
                copy[i + 1][j].rgbtBlue +
                copy[i + 1][j + 1].rgbtBlue);
                image[i][j].rgbtRed = round(addRed / 9);
                image[i][j].rgbtGreen = round(addGreen / 9);
                image[i][j].rgbtBlue = round(addBlue / 9);
            }
            addRed = 0;
            addGreen = 0;
            addBlue = 0;
        }
    }
    return;
}
