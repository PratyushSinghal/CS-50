#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int get_letters(string input);
int get_words(string input);
int get_sentences(string input);

int main(void)
{
    string input = get_string("Please enter the text: ");
    int letters = get_letters(input);
    int words = get_words(input);
    int sentences = get_sentences(input);
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int get_letters(string input)
{
    int count = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if ((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122))
        {
            count++;
        }
    }
    return count;
}

int get_words(string input)
{
    int count = 1;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

int get_sentences(string input)
{
    int count = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if ((input[i] == '.') || (input[i] == '?') || (input[i] == '!'))
        {
            count++;
        }
    }
    return count;
}
