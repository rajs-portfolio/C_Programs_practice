#include <stdio.h>

int main() {
    int number, original, reverse = 0, digit;
    printf("Enter a number: ");
    scanf("%d", &number);

    original = number;

    while (number > 0) {
        digit = number % 10;
        reverse = reverse * 10 + digit;
        number /= 10;
    }

    number = reverse;
    
    while (number > 0) {
        digit = number % 10;


        if (digit == 0 || original % digit != 0) {
            printf("No\n");
            return 0; 
        }

        number /= 10; 
    }
    printf("Yes\n");
    
    return 0;
}