#include <stdio.h>

int main() {
    int n, i;
    int sum_even = 0, product_odd = 1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            sum_even += arr[i];
        } else {
            product_odd *= arr[i];
        }
    }

    printf("Sum of even elements: %d\n", sum_even);
    printf("Product of odd elements: %d\n", product_odd);

    return 0;
}
