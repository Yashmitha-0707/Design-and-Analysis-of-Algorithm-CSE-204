#include <stdio.h>

struct Result {
    int max;
    int min;
};

struct Result findMaxMin(int a[], int low, int high) {
    struct Result result, left, right;
    int mid;

    if (low == high) {
        result.max = a[low];
        result.min = a[low];
        return result;
    }

    if (high == low + 1) {
        if (a[low] > a[high]) {
            result.max = a[low];
            result.min = a[high];
        } else {
            result.max = a[high];
            result.min = a[low];
        }
        return result;
    }


    mid = (low + high) / 2;


    left = findMaxMin(a, low, mid);
    right = findMaxMin(a, mid + 1, high);

    result.max = (left.max > right.max) ? left.max : right.max;
    result.min = (left.min < right.min) ? left.min : right.min;

    return result;
}

int main() {
    int a[100], n, i;
    struct Result result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    result = findMaxMin(a, 0, n - 1);

    printf("Maximum = %d\n", result.max);
    printf("Minimum = %d\n", result.min);

    return 0;
}
