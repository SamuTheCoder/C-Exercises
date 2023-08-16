#include <stdio.h>

int main()
{
    int difference = 0, array_size = 0, pair_counter = 0;
    int array[20];
    int pairs[10][2];

    printf("Insert the array size: ");
    scanf("%d", &array_size);

    printf("Insert the array:\n");

    for (size_t i = 0; i < array_size; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Difference: ");
    scanf("%d", &difference);

    for (size_t i = 0; i < array_size; i++)
    {
        for (size_t j = 0; j < array_size; j++)
        {
            if (i == j)
                continue;
            if (array[i] - array[j] == difference)
            {
                pairs[pair_counter][0] = array[i];
                pairs[pair_counter][1] = array[j];
                pair_counter++;
            }
        }
    }

    printf("There were %d pairs found with difference %d: \n", pair_counter + 1, difference);

    for (size_t i = 0; i < pair_counter; i++)
    {
        printf("[%d, %d] ", pairs[i][0], pairs[i][1]);
    }
}
