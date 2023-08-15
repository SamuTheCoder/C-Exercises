#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int sequence[100];
    int subsequence[100];
    int sequence_size;

    int current_index = 0, first_index = 0, max_size = 1;
    int max_start_index = 0;

    printf("Introduce sequence size: \n");
    scanf("%d", &sequence_size);

    printf("Introduce the numbers: \n");
    for (size_t i = 0; i < sequence_size; i++)
    {
        scanf("%d", &sequence[i]);
    }

    for (size_t i = 0; i < sequence_size; i++)
    {
        // 5 4 1 2 3 2 6 7 8
        if (i == sequence_size - 1)
        {
            if (max_size < (i - first_index) + 1)
            {
                max_size = (i - first_index) + 1;
                max_start_index = first_index;
                break;
            }
        }

        if (sequence[i] <= sequence[i - 1] && i != 0)
        {
            if (first_index == 0)
            {
                max_size = i;
                max_start_index = first_index;
            }
            else
            {
                if (max_size < i - first_index)
                {
                    max_size = i - first_index;
                    max_start_index = first_index;
                }
            }
            first_index = i;
        }
    }

    memcpy(subsequence, sequence + max_start_index, max_size * sizeof(int));

    printf("Longest ascending contiguous subsequence is: \n[");

    for (size_t i = 0; i < max_size; i++)
    {
        printf("%d ", subsequence[i]);
    }
    printf("]");
}
