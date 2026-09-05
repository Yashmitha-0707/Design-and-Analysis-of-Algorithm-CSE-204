#include <stdio.h>

void bucketSort(int a[], int n)
{
    int bucket[10][100];
    int count[10] = {0};
    int i, j, k, index;

    
    for (i = 0; i < n; i++)
    {
        index = a[i] / 10;

        if (index > 9)
            index = 9;

        bucket[index][count[index]++] = a[i];
    }

   
    for (i = 0; i < 10; i++)
    {
        for (j = 1; j < count[i]; j++)
        {
            int key = bucket[i][j];
            k = j - 1;

            while (k >= 0 && bucket[i][k] > key)
            {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }

            bucket[i][k + 1] = key;
        }
    }

        index = 0;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < count[i]; j++)
        {
            a[index++] = bucket[i][j];
        }
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    bucketSort(a, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}