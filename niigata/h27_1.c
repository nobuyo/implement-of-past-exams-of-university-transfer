#include <stdio.h>

int main(void) {
    int i;
    int n;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        if (i % 3 == 0 || i % 10 == 3 || (i - 30 <= 9 && i - 30 >= 0)) {
            printf("%d, ", i);
        }
    }
    return 0;
}

// bekkai
// int main(void) {
//     int i;
//     int n;

//     scanf("%d", &n);

//     for (i=1; i<=n; i++) {
//         if (i/10 == 3 || i%10 == 3 || i%3 == 0) printf("%d ", i);
//     }

//     printf("\n");

//     return 0;
// }