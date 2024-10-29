#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int scorecount(string word);
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string input1 = get_string("Player1: ");
    string input2 = get_string("Player2: ");
    int score1 = scorecount(input1);
    int score2 = scorecount(input2);
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

int scorecount(string word)
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            score = score + points[word[i] - 65];
        }
        if (islower(word[i]))
        {
            score = score + points[word[i] - 97];
        }
    }
    return score;
}
