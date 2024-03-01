#include <stdio.h>
#include <stdlib.h>


void quickSort(int a[], int low, int high){
    if(low < high){
        int pivot=a[high];
        int i = low - 1, temp, j;

        for (j=low; j<=high-1; j++)
            {
                if (a[j] < pivot)
                {
                    ++i;
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
        }
        temp = a[i+1];
        a[i + 1] = a[high];
        a[high] = temp;
        quickSort(a, low, i);
        quickSort(a, i + 2, high);
    }
}



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

    quickSort(a, 0, n - 1);

    printf("\nSorted result: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    free(a); // Free dynamically allocated memory
    return 0;
}