#include <stdio.h>

int main()
{ 
    int n, i, pos, key;
    pos = 1;

    printf("Enter n\n");
    scanf("%d", &n);
    int a[n];

    printf("Enter elements of  an array\n");
    for(i = 0; i < n; i++)
    {   printf("Element %d is :",i+1);
        scanf("%d", &a[i]);
    }

    printf("Enter the element to search \n");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            pos =pos+ i;
        }
    }

    if(pos == 1)
    {
        printf("Element is not found in the array");
    }
    else
    {
        printf("Element found at %d position", pos);
    }

    return 0;
}