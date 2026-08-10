#include <stdio.h>

void reverse(int a[], int start, int end) {
    int temp;

    while (start < end) {
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;

        start++;
        end--;
    }
}

int main() {
    int a[100], n, k, i;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter K: ");
    scanf("%d", &k);

    k = k % n;

    reverse(a, 0, n - 1);
    reverse(a, 0, k - 1);
    reverse(a, k, n - 1);

    printf("Rotated array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
