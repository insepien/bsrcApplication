#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <string>

using namespace std;

void scrabble();
void readability();
void substitution();


int main(void)
{
    return 0;
}

// 1. SCRABBLE

int POINTS[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };

void scrabble()
{
    int compute_score(string word);
    // Get input words from both players
    string word1;
    cout << "Player 1: " << endl;
    getline(cin, word1);
    string word2;
    cout << "Player 2: " << endl;
    getline(cin, word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Ties");
    }
    printf("\n");

}

int compute_score(string word) //func for scrabble
{
    // TODO: Compute and return score for string
    // A-Z 65-90.
    int score = 0;
    //word = toupper(word);
    for (int i = 0; i < word.length(); i++)
    {
        char cha = toupper(word[i]);
        int chascore = POINTS[int(cha) - 65];
        score += chascore;
    }

    return score;
}


// 2. READABILITY

void readability()
{
    string text;
    cout << "Text: " << endl;
    getline(cin, text);
    int sentences = 0;
    int letters = 0;
    int words = 1;
    for (int i = 0; i < text.length(); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        if (isspace(text[i]))
        {
            words++;
        }
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    float letterper100 = (letters * 100.0) / words;
    float sentenceper100 = (sentences * 100.0) / words;
    float index = round(0.0588 * letterper100 - 0.296 * sentenceper100 - 15.8);

    if (index < 1)
    {
        cout << "Before grade 1" << endl;
    }
    else if (index > 16)
    {
        cout << "Grade 16+" << endl;
    }
    else
    {
        cout << "Grade " << index << endl;
    }

}

// 3. SUBSTITUTION
void substitution()
{
    string key;
    bool keyvalid = false;
    do
    {
        cout << "Key: " << endl;
        getline(cin, key);
        if (key.length() == 26)
        {
            keyvalid = true;
            for (int i = 0; i < key.length(); i++)
            {
                if (isalpha(key[i]))
                {
                    keyvalid = true;
                }
                for (int j = 0; j < key.length(); j++)
                {
                    if (j != i && key[i] == key[j])
                    {
                        keyvalid = false;
                    }
                }
            }
        }

    } while (keyvalid == false);


    string word;
    cout << "Text: " << endl;
    getline(cin, word);
    string translation = word;
    for (int i = 0; i < word.length(); i++)
    {
        if (isspace(translation[i]) || !(isalpha(translation[i])))
        {
            translation[i] = translation[i];
        }
        else
        {
            translation[i] = key[int(toupper(word[i])) - 65];
            if (islower(word[i]))
            {
                translation[i] = tolower(translation[i]);
            }
        }
    }

    cout << translation << endl;
}

