#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    for (int a = 1; a <= n / 2; a++) {
        int b = 0;
        int temp = a;
        while (temp > 0) {
            b = b * 10 + temp % 10;
            temp /= 10;
        }

        if (a + b == n) {
            printf("%d is the mystery number.\n", n);
            break;
        }
        else{
            printf("%d is not a mystery number.\n", n);
            break;
        }
    }

    return 0;
}
