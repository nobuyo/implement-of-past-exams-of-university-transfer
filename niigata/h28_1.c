#include <stdio.h>

int main(void) {
    int i, j;
    for (i = 2; i <= 1000; i++) {
        int sum = 0;
        for (j = 1; j < i; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }
        if (sum == i) {
            printf("%d, ", sum);
        }
    }

    return 0;
}
