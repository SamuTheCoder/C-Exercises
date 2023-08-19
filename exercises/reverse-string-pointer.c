#include <stdio.h>
#include <string.h>

#define MAX_STR_SIZE 50
int main()
{
    char str[MAX_STR_SIZE];
    char *start_pointer;
    char *end_pointer;
    int string_size;

    // https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf
    // scanf stops scanning after a space is inserted, use fgets to get str and sscanf to evaluate it
    printf("Insert a string: ");
    fgets(str, MAX_STR_SIZE, stdin);

    string_size = strlen(str);
    /*for (size_t i = 0; i < string_size; i++)
    {
        if (str[i] == '\n')
        {
            printf("%d", i);
            break;
        }
    }*/

    if ((string_size > 0) && (str[string_size - 1] == '\n'))
    {
        str[string_size - 1] == '\0';
    }

    string_size--; // minus 1 because there's a \n at the very end

    start_pointer = &str[0];
    // I had &str[string_size - 1] assigned to end_pointer before, which is equal to the last char,
    // which is the null terminator (string_size -1 = 12, previously size = 13, now it's 12), thus
    // the string was being terminated at the beginning
    end_pointer = &str[string_size - 1];
    char aux;
    for (size_t i = 0; i < (string_size) / 2; i++)
    {
        aux = *end_pointer;
        *end_pointer = *start_pointer;
        *start_pointer = aux;

        start_pointer++;
        end_pointer--;
    }

    printf("String reversed is: %s", str);

    return 0;
}