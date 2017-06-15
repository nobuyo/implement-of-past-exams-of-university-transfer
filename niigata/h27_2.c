#include <stdio.h>

int main(void) {
    int i, j, k;
    int digit_1_row;
    int digit_1;
    int digit_2_row;
    int digit_2;
    int digit_3;

    for (i = 0; i <= 10; i++) {
        for (j = 0; j <= 10; j++) {
            for (k = 0; k <= 10; k++) {
                if (i == j || i == k) continue;
                digit_1_row = i + j;
                digit_1 = digit_1_row % 10;
                digit_2_row = i + k + digit_1_row / 10;
                digit_2 = digit_2_row % 10;
                digit_3 = digit_2_row / 10;

                if (i == digit_1 && j == digit_2 && i == digit_3) {
                    printf("%d%d + %d%d = %d%d%d\n", i, j, k, i, i, j, i);
                }
            }
        }
    }
    return 0;
}
