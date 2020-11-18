#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int LETTERS = 0;
int WORDS = 0;
int SENTENCES = 0;

void letter_counter(string text);

int main(void)
{

    float index = 0.0;
    string output ;
    string text = get_string("text :\n");

    letter_counter(text);

    float L = ((float)LETTERS / WORDS) * 100;
    float S = ((float)SENTENCES / WORDS) * 100;

    index  = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1");
    }
    else if (index >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i", (int)round(index));
    }

    printf("\n");
}

void letter_counter(string text)
{

    for (int i = 0, n = strlen(text)  ; i < n  ; i++)
    {

        if (isalpha(text[i]) != 0)
        {
            LETTERS++;
        }

        if (text[i] == ' ' || i == 0)
        {
            WORDS++;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            SENTENCES++;
        }
    }
}