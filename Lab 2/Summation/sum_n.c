#include <stdio.h>

int main()
{
    int x, n, i;
    int power = 1, sum = 0;

    printf("Enter x and n: ");
    scanf("%d %d", &x, &n);

    for(i = 0; i <= n; i++)
    {
        sum = sum + power;
        power = power * x;
    }

    printf("Sum = %d", sum);

    return 0;
}