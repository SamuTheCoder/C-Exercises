#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 200
#define MAX_WORD_SIZE 20

int replace_chars_in_string(char **string, char *word_to_replace, char *replacement_word);

int main()
{
    char *string = (char *)malloc(MAX_STRING_SIZE * sizeof(char));
    char *word_to_replace = (char *)malloc(MAX_WORD_SIZE * sizeof(char));
    char *replacement_word = (char *)malloc(MAX_WORD_SIZE * sizeof(char));

    printf("Enter your string: \n");
    fgets(string, MAX_STRING_SIZE, stdin);

    printf("Word to replace: \n");
    scanf("%s", word_to_replace);

    printf("Replacement word: \n");
    scanf("%s", replacement_word);

    int boolean = 1;
    while (1)
    {
        boolean = replace_chars_in_string(&string, word_to_replace, replacement_word);
        if (boolean == 0)
        {
            break;
        }
    }

    printf("The new phrase is: %s\n", string);

    free(string);
    free(word_to_replace);
    free(replacement_word);
}

int replace_chars_in_string(char **string, char *word_to_replace, char *replacement_word)
{
    char *occurence = strstr(*string, word_to_replace);

    if (occurence == NULL)
    {
        return 0;
    }

    int difference = strlen(replacement_word) - strlen(word_to_replace);

    if (difference > 0)
    {
        // change size to size plus difference between the words
        *string = realloc(*string, (MAX_STRING_SIZE + difference) * sizeof(char));

        // shift the chars after the word to replace to the furthest right
        memmove(occurence + strlen(replacement_word), (occurence + strlen(word_to_replace)), strlen(occurence + strlen(word_to_replace)) + 1);
        
    }

    else if(difference < 0)
    {
        // shift chars after the word to replace to the furthest left
        memmove(occurence + strlen(replacement_word), occurence + strlen(word_to_replace), strlen(occurence + strlen(word_to_replace)) + 1);
        // difference is negative
        *string = realloc(*string, (MAX_STRING_SIZE + difference) * sizeof(char));
        
    }
    // insert the replacement word

    memcpy(occurence, replacement_word, strlen(replacement_word));

    return 1;
}