#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, temp;
    int n;
    printf("Enter array size: ");
    scanf_s("%d", &n);

    int *a = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory

    printf("Enter values in array: ");
    for (i = 0; i < n; i++)
    {
        scanf_s("%d", &a[i]);
    }

    for (i = n; i > 0; i--)
    {
        for (j = 0; j < i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("\nSorted result: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    free(a); // Free dynamically allocated memory
    return 0;
}