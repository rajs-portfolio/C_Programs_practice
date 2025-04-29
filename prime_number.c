#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Neither prime nor composite\n");
        return 0;
    }

    int c = 2;
    while (c * c <= n) {
        if (n % c == 0) {
            printf("Not prime\n");
            return 0;
        }
        c++;
    }

    printf("Prime\n");
    return 0;
}