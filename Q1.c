#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, x;
    int largest = INT_MIN, second = INT_MIN;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);

        if (x > largest) {
            second = largest;
            largest = x;
        }
        else if (x > second && x != largest) {
            second = x;
        }
    }

    if (second == INT_MIN)
        printf("No second largest distinct element.");
    else
        printf("Second largest = %d", second);

    return 0;
}
