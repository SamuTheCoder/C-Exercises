#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 200
#define MAX_WORD_SIZE 20

char *replace_chars_in_string(char *string, char *word_to_replace, char *replacement_word);

int main()
{
    char *string = (char *)malloc(MAX_STRING_SIZE * sizeof(char));
    char *word_to_replace = (char *)malloc(MAX_WORD_SIZE * sizeof(char));
    char *replacement_word = (char *)malloc(MAX_WORD_SIZE * sizeof(char));

    printf("Enter your string: \n");
    fgets(string, MAX_STRING_SIZE, stdin);
    //Eliminate the \n at the end of fgets input
    string[strcspn(string, "\n")] = 0;

    printf("Word to replace: \n");
    scanf("%s", word_to_replace);

    printf("Replacement word: \n");
    scanf("%s", replacement_word);

    string = replace_chars_in_string(string, word_to_replace, replacement_word);

    printf("The new phrase is: %s\n", string);

    free(string);
    free(word_to_replace);
    free(replacement_word);
}

char *replace_chars_in_string(char *string, char *word_to_replace, char *replacement_word)
{
    char *occurence = "";

    while (occurence != NULL)
    {
        //strstr finds the first occurrence of the word
        occurence = strstr(string, word_to_replace);
        if (occurence == NULL)
        {
            break;
        }

        int difference = strlen(replacement_word) - strlen(word_to_replace);

        if (difference > 0)
        {
            //increase size to hold new word
            char * temp = string + strlen(string);
            temp = (char *) malloc(difference); 

            // shift the chars after the word to replace to the furthest right
            memmove(occurence + strlen(replacement_word), (occurence + strlen(word_to_replace)), strlen(occurence + strlen(word_to_replace)) + 1);
            free(temp);
        }

        else if (difference < 0)
        {
            // shift chars after the word to replace to the furthest left
            memmove(occurence + strlen(replacement_word), occurence + strlen(word_to_replace), strlen(occurence + strlen(word_to_replace)) + 1);
        }
        // insert the replacement word

        memcpy(occurence, replacement_word, strlen(replacement_word));
    }

    return string;
}