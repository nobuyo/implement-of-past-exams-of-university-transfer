#include <stdio.h>

int calc(int type[]) {
    int i;
    int n = 1;
    int sum = 0;

    for (i = 0; i <= 8; i++, n++) {  
        switch(type[i]) {
        case 0:
            sum += n;
            break;
        case 1:
            sum -= n;
            break;
        case 2:
            sum += n;
            break;
        }
        if (i == 8) break;
        if (type[i + 1] == 0) {
            sum *= 10;
        }
    }
    printf("%d%d%d%d%d%d%d%d%d\n", type[8], type[7], type[6], type[5], type[4], type[3], type[2], type[1], type[0]);
    printf("%d\n", sum);

    return sum;
}

int main(void) {
    int i, j;
    int idx[9];

    for (idx[0] = 0; idx[0] < 3; idx[0]++) {
        for (idx[1] = 0; idx[1] < 3; idx[1]++) {
            for (idx[2] = 0; idx[2] < 3; idx[2]++) {
                for (idx[3] = 0; idx[3] < 3; idx[3]++) {
                    for (idx[4] = 0; idx[4] < 3; idx[4]++) {
                        for (idx[5] = 0; idx[5] < 3; idx[5]++) {
                            for (idx[6] = 0; idx[6] < 3; idx[6]++) {
                                for (idx[7] = 0; idx[7] < 3; idx[7]++) {
                                    for (idx[8] = 0; idx[8] < 3; idx[8]++) {
                                        // printf("%d%d%d%d%d%d%d%d%d\n", idx[0], idx[1], idx[2], idx[3], idx[4], idx[5], idx[6], idx[7], idx[8]);
                                        int sum = calc(idx);
                                        if (sum == 100) {
                                            printf("%d%d%d%d%d%d%d%d%d\n", idx[0], idx[1], idx[2], idx[3], idx[4], idx[5], idx[6], idx[7], idx[8]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
