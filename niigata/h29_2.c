#include <stdio.h>
#include <math.h>

int main(void) {
    int i, j;
    int ope[9], num[9];
    int tmp, sum;
    int max = pow(3,9);

    for (i = 0; i < max; i++) {
        sum = 0;
        tmp = i;
        for (j = 0; j<9; j++) {
            ope[j] = tmp%3;
            tmp /= 3;
        }

        for (j = 0; j<9; j++) {
            tmp = 0;
            if (ope[j] == 0 && j != 0) {
                if (num[j-1]<0) {
                    tmp = (j+1) * (-1);
                }
                else {
                    tmp = j+1;
                }
                num[j] = num[j-1] * 10 + tmp;
                num[j-1] = 0;
            }
            else if (ope[j] == 0 && j == 0) {
                num[j] = j+1;
            }
            else if (ope[j] == 1) {
                num[j] = j+1;
            }
            else if (ope[j] == 2) {
                num[j] = (j+1) * (-1);
            }
        }


        for (j = 0; j<9; j++) {
            sum += num[j];
            // printf("%d ", num[j]);
        }
        // putchar('\n');
        // for (j = 0; j<9; j++) {
        //     printf("%d ", ope[j]);
        // }
        // putchar('\n');
        // putchar('\n');

        if (sum == 100) {
            for (j = 0; j<9; j++) {
                if (ope[j] == 0) {
                    printf("%d", j+1);
                }
                else if (ope[j] == 1) {
                    printf("+%d", j+1);
                }
                else if (ope[j] == 2) {
                    printf("-%d", j+1);
                }
            }
            putchar('\n');
        }
    }
    return 0;
}