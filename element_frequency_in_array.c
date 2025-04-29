#include <stdio.h>
#define MAX 10

int main() {
    int a[MAX], i, count = 0, x;
    printf("Enter %d elements: \n", MAX);
    for (i = 0; i < MAX; i++) {
        scanf("%d", &a[i]);
    }


    printf("Enter a number to search: \n");
    scanf("%d", &x);


    for (i = 0; i < MAX; i++) {
        if (a[i] == x) {
            count++;
        }
    }


    if (count > 0) {
        printf("%d is found %d times\n", x, count);
    } else {
        printf("%d is not found\n", x);
    }

    return 0;
}
