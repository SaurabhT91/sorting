#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int *leftArray, int ls, int *rightArray, int rs)
{
    int i = 0, j = 0, k = 0;
    while (i < ls && j < rs)
    {
        if (leftArray[i] <= rightArray[j])
        {
            a[k] = leftArray[i];
            i++;
        }
        else
        {
            a[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < ls)
    {
        a[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < rs)
    {
        a[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int *a, int n)
{
    if (n < 2)
        return;

    int ls = n / 2;
    int rs = n - ls;

    int *leftArray = (int *)malloc(ls * sizeof(int));
    int *rightArray = (int *)malloc(rs * sizeof(int));

    if (leftArray == NULL || rightArray == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < ls; i++)
    {
        leftArray[i] = a[i];
    }

    for (int i = ls; i < n; i++)
    {
        rightArray[i - ls] = a[i];
    }

    mergeSort(leftArray, ls);
    mergeSort(rightArray, rs);
    merge(a, leftArray, ls, rightArray, rs);

    free(leftArray);
    free(rightArray);
}

int main()
{
    int size;

    printf("Enter array size: ");
    if (scanf("%d", &size) != 1 || size <= 0)
    {
        printf("Invalid array size\n");
        return EXIT_FAILURE;
    }

    int *a = (int *)malloc(size * sizeof(int)); // Dynamically allocate memory

    if (a == NULL)
    {
        printf("Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    printf("Enter values in array: ");
    for (int i = 0; i < size; i++)
    {
        if (scanf("%d", &a[i]) != 1)
        {
            printf("Invalid input\n");
            free(a);
            return EXIT_FAILURE;
        }
    }

    mergeSort(a, size);

    printf("\nSorted result: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }

    free(a); // Free dynamically allocated memory
    return 0;
}
