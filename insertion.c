#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, temp;
    int n, m, loc;
    printf("Enter array size: ");
    scanf_s("%d", &n);

    int *a = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory

    printf("Enter values in array: ");
    for (i = 0; i < n; i++)
    {
        scanf_s("%d", &a[i]);
    }

    for (i=1; i<n ; i++)
    {
        for (j=i; j>=1; j--)
        {
        //     if (a[j - 1] < a[j])
        //     {
        //         temp = a[j-1];
        //         a[j-1] = a[j];     // FOR DESECENDING
        //         a[j] = temp;
        //    }
           if (a[j - 1] > a[j])
           {
               temp = a[j - 1];
               a[j - 1] = a[j];
               a[j] = temp;
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