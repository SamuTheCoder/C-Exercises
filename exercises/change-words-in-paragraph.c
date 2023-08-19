#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 200
#define MAX_WORD_SIZE 20
int main()
{
    char *string = (char *)malloc(MAX_STRING_SIZE * sizeof(char));
    char *word_to_replace = (char *)malloc(MAX_WORD_SIZE * sizeof(char));
    char *replacement_word = (char *)malloc(MAX_WORD_SIZE * sizeof(char));

    char *start_pointer = string;
    char *end_pointer = string;

    printf("Enter your string: \n");
    fgets(string, MAX_STRING_SIZE, stdin);

    printf("Word to replace: \n");
    scanf("%s", &word_to_replace);

    printf("Replacement word: \n");
    scanf("%s", &replacement_word);

    char test_word[MAX_WORD_SIZE];
    int test_word_size = 0;
    for (size_t i = 0; i < strlen(string); i++)
    {
        if (*(string + i) == *(replacement_word))
        {
            start_pointer = end_pointer = string + i;
            for (size_t j = 1; j < strlen(replacement_word); j++)
            {
                if (*(start_pointer + j) == *(replacement_word + j))
                {
                    end_pointer += j;
                }
            }
        }

        /*if (test_word == replacement_word)
        {
        }
        //if first letter
        if (*(string + i) == *(replacement_word))
        {
            //rest of the letters
            for (size_t j = 1; j < strlen(replacement_word); j++)
            {
                if (*(string + i + j) == *(replacement_word + j))
                {
                }
            }
        }*/
    }
}