// source: https://leetcode.com/problems/beautiful-arrangement-ii

#include <stdio.h>
#include <stdlib.h>

int *constructArray(int n, int k, int *returnSize)
{
    *returnSize = n;

    int *result = (int *)malloc(n * sizeof(int));
    char *taken = (char *)malloc(n * sizeof(char));

    // set first elem
    result[0] = 1;
    taken[0] = 1;

    for (int i = 1; i < n; i++)
    {
        if (k == 0)
        {
            result[i] = i + 1;
            continue;
        }

        int val = result[i - 1] - k;
        if (val < 1 || taken[val - 1])
            val = result[i - 1] + k;

        k--;
        result[i] = val;
        taken[val - 1] = 1;
    }

    return result;
}

void main(void)
{
    int arr_size;
    int *arr = constructArray(10, 2, &arr_size);

    printf("\n");
    for (size_t i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}
