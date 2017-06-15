#include <stdio.h>

int main(void) {
    int i;
    int f[100];

    f[0] = 1;
    f[1] = 1;
    printf("f[1] = %d\n", f[0]);
    printf("f[2] = %d\n", f[1]);
    for (i = 2; ; i++) {
        f[i] = f[i - 1] + f[i - 2];
        if (f[i] > 1000) break;
        printf("f[%d] = %d\n", i + 1, f[i]);
    }

    return 0;
}
