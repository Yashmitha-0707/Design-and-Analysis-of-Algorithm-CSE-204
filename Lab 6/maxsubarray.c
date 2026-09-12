#include <stdio.h>
#include <limits.h>

struct Subarray {
    int left;
    int right;
    int sum;
};

struct Subarray maxCrossingSum(int a[], int low, int mid, int high) {
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int sum = 0;
    int i;
    int maxLeft = mid;
    int maxRight = mid + 1;
    for (i = mid; i >= low; i--) {
        sum = sum + a[i];

        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    sum = 0;

    for (i = mid + 1; i <= high; i++) {
        sum = sum + a[i];

        if (sum > rightSum) {
            rightSum = sum;
            maxRight = i;
        }
    }

    struct Subarray result;
    result.left = maxLeft;
    result.right = maxRight;
    result.sum = leftSum + rightSum;

    return result;
}

struct Subarray maxSubarray(int a[], int low, int high) {
    struct Subarray left, right, cross, result;
    int mid;


    if (low == high) {
        result.left = low;
        result.right = high;
        result.sum = a[low];
        return result;
    }

    mid = (low + high) / 2;


    left = maxSubarray(a, low, mid);
    right = maxSubarray(a, mid + 1, high);
    cross = maxCrossingSum(a, low, mid, high);

    
    if (left.sum >= right.sum && left.sum >= cross.sum)
        return left;
    else if (right.sum >= left.sum && right.sum >= cross.sum)
        return right;
    else
        return cross;
}

int main() {
    int a[100], n, i;
    struct Subarray result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    result = maxSubarray(a, 0, n - 1);

    printf("Maximum subarray: ");

    for (i = result.left; i <= result.right; i++)
        printf("%d ", a[i]);

    printf("\nMaximum sum = %d\n", result.sum);

    return 0;
}
