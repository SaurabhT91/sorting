#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, temp;
    int n,m,loc;
    printf("Enter array size: ");
    scanf_s("%d", &n);

    int *a = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory

    printf("Enter values in array: ");
    for (i = 0; i < n; i++)
    {
        scanf_s("%d", &a[i]);
    }

    for (i=0; i<n-1; i++)
    {
        m=a[i];
        loc=i+1;
        for (j=i+1; j<n; j++)
        {
            if (m > a[j])
            {
                m = a[j];
                loc = j;
            }
        }
        if(a[loc]<a[i]){
            temp = a[loc];
            a[loc] = a[i];
            a[i] = temp;
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