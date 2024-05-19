#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    float numLetters = count_letters(text);
    float numWords = count_words(text);
    float numSentences = count_sentences(text);

    float L = (numLetters / numWords) * 100;
    float S = (numSentences / numWords) * 100;

    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int grade = round(index);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int numAlpha = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            numAlpha++;
        }
    }
    return numAlpha;
}

int count_words(string text)
{
    int numSpace = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            numSpace++;
        }
    }
    return numSpace + 1;
}

int count_sentences(string text)
{
    int numPunctuation = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            numPunctuation++;
        }
    }
    return numPunctuation;
}
