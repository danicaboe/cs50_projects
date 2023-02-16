make#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string input);
char rotate(char c, int n);
int main(int argc, string argv[])
{
//string will be entered by user. argc will be number of words entered by user. ./caesar will be argc[1] so anything greater that that will be the input.
//iterate through each letter in string. get input from user on how many spaces to shift letters. (k)
// since key and message will be received from user -all we need to do is manipulate input using argv[argc];
//first - ask user for k - a non-negative integer
    if (argc < 2 || argc > 2 || only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k = atoi(argv[1]);
    // printf("%i\n", k);
// Ask user for a string and preface it "plaintext:"
    string plainText = get_string("plaintext: ");
    int p = strlen(plainText);
    printf("ciphertext: ");
    for (int i = 0; i < p; i++)
    {
        printf("%c", rotate(plainText[i], k));
    }
    printf("\n");
    // printf("%c", cipher[i]);
    // // printf("%s\n", plainText);
    // char output = rotate('F', k);
    // printf("%c\n",output);
}
//need to check input in command line for number
bool only_digits(string input)
{
    bool x;
    int n = strlen(input);
    for (int i = 0; i < n; i++)
    {
        x = isdigit(input[i]);
    }
    return x;
}
char rotate(char c, int n)
{
    int s;
    if (c >= 65 && c <= 90)
    {
        s = ((c - 65) + n) % 26;
        s += 65;
    }
    else if (c >= 97 && c <= 122)
    {
        s = ((c - 97) + n) % 26;
        s += 97;
    }
    else
    {
        s = c;
    }
    return s;
}