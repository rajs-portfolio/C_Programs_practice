#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");

    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1; 
    }

    if (n <= 0) {
        printf("Invalid input. Please enter a positive number.\n");
        return 1;
    }

    int sum = 0, temp = n, quo;
    int primeno = 1;

    while (temp != 0) {
        sum += temp % 10;
        temp /= 10;
    }

    if (n % sum == 0) {
        quo = n / sum;

        if (quo < 2) {
            primeno = 0;
        } else {
            for (int i = 2; i <= quo / 2; i++) {
                if (quo % i == 0) {
                    primeno = 0;
                    break;
                }
            }
        }

        if (primeno) {
            printf("Yes, it is a Moran number\n");
        } else {
            printf("No, it is not a Moran number\n");
        }
    } else {
        printf("No, it is not a Moran number\n");
    }

    return 0;
}
