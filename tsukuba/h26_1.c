#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int cnt_1 = 0;
int cnt_2 = 0;

unsigned int check_flag(unsigned int *flag, unsigned int p) {
    if (flag[p] != 0) {
        cnt_1++;
    }
    return flag[p];
}

unsigned int check_flag2(unsigned int *flag, unsigned int p) {
    // (4)
    return (flag[p / 32] & (1 << (p % 32)));
}

void reset_flag(unsigned int *flag, unsigned int p) {
    flag[p] = 0;
    cnt_2++;
}

void reset_flag2(unsigned int *flag, unsigned int p) {
    flag[p / 32] &= ~(1 << (p % 32));
}

void prime1(unsigned int max) {
    unsigned int p, i;
    int count = 0;
    unsigned int *flag =
        (unsigned int *) malloc(sizeof(unsigned int) * (max + 1));

    // initialization of all flags
    for (p = 2; p <= max; p++) {
        flag[p] = 1;
    }

    // sieving (FURUI NI KAKERU)
    for (p = 2; p * p <= max; p++) {
        if (check_flag(flag, p) != 0) {
            for (i = p * p; i <= max; i += p) {
                reset_flag(flag, i);
            }
        }
    }

    // output
    for (p = 2; p <= max; p++) {
        if (check_flag(flag, p) != 0) {
            // printf("%d ", p);
        }
    }
    // printf("\n");
}

void prime2(unsigned int max) {
    unsigned int p, i;
    unsigned int words = ceil((double) (max + 1) / 32);
    unsigned int *flag =
        (unsigned int *) malloc(sizeof(unsigned int) * words);

    // initialization of all flags
    for (i = 0; i < words; i++) {
        flag[i] = 0xFFFFFFFF;
    }

    if (max == 1000) {
        printf("prime2(%d): allocated %lubyte. words length is %d.\n", max, sizeof(unsigned int) * words, words);
    }

    // sieving (FURUI NI KAKERU)
    for (p = 2; p * p <= max; p++) {
        if (check_flag2(flag, p) != 0) {
            for (i = p * p; i <= max; i += p) {
                reset_flag2(flag, i);
            }
        }
    }

    // output
    for (p = 2; p <= max; p++) {
        if (check_flag2(flag, p) != 0) {
            // printf("%d ", p);
        }
    }
    // printf("\n");

    if (max == 10) {
        printf("prime2(%d): flag[0] = %x\n", max, flag[0]);
    }
 }

int main(void) {
    // (1)
    prime1(10);
    printf("prime1(10): check_flag() returned 0 for %d times.\n", cnt_1);
    cnt_1 = 0;
    cnt_2 = 0;

    // (2)
    prime1(100);
    printf("prime1(100): reset_flag() called for %d times.\n", cnt_2);
    cnt_1 = 0;
    cnt_2 = 0;

    // (3)
    prime2(1000);

    // (5)
    prime2(10);

    return 0;
}
