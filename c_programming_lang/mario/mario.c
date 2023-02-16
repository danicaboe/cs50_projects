#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get value from user
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

// for each row - each row adds one more until bottom row contains total in height
// print one hash on one line - next line print 2, third, print 3
    for (int i = 0; i < n; i++)
    {
        //for each column - determined by height
        for (int j = 0; j < n; j++)
        {
            if (j + i >= n - 1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}