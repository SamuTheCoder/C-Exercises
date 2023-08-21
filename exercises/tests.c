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
        *(replacement_word + i) = 'A' + i;
    }

    int len = strlen(replacement_word);
    printf("%d\n", len);
    printf("%s\n", replacement_word);

    replacement_word = realloc(replacement_word, 6);

    char *endpointer = replacement_word+5;
    *endpointer = 'x';
    printf("Last char: %c\n", *(endpointer));
    char *pointer = replacement_word + 4;

    char aux;
    for (size_t i = 0; i < 5; i++)
    {
        aux = *(pointer);
        *(pointer) = *(endpointer);
        *(endpointer) = aux;

        endpointer--;
        pointer--;
    }
    
    len = strlen(replacement_word);
    printf("aaaaaaaaa %d\n", len);
    printf("%s", replacement_word);
    free(replacement_word);
    free(word_to_replace);
}