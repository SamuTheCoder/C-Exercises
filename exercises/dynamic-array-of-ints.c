#include <stdio.h>
#include <stdlib.h>

int main()
{

    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *array_ptr = (int *)malloc(size * sizeof(int));

    // check if malloc was successful
    if (array_ptr == NULL)
    {
        printf("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < size; i++)
    {
        // works the same as *(array_ptr + i)
        array_ptr[i] = i + 1;
    }

    printf("Array Elements: ");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", *(array_ptr + i));
    }

    free(array_ptr);
    return 0;
}