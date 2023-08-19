#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 200
#define MAX_WORD_SIZE 5
int main()
{
    char *word_to_replace = (char *)malloc(MAX_WORD_SIZE * sizeof(char));
    char *replacement_word = (char *)malloc(MAX_WORD_SIZE * sizeof(char));

    for (size_t i = 0; i < 5; i++)
    {
        *(replacement_word + i) = "A";
    }

    printf("%d", strlen(replacement_word));
}