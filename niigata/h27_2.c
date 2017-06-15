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

// bekkai
// int main(void) {
//     int a,b,c;
//     int tmp;

//     for (a=0; a<10; a++) {
//         for (b=0; b<10; b++) {
//             for (c=0; c<10; c++) {
//                 tmp = (a+c) + (a+b)/10;
//                 if (a == b || b == c || c == a) continue;
//                 if ((a+b)%10 == a && tmp%10 == b && tmp/10 == a) {
//                     printf(" %d%d\n", a, b);
//                     printf("+%d%d\n", c, a);
//                     printf("%d%d%d\n", a, b, a);
//                 }
//             }
//         }
//     }
//    return 0;
// }