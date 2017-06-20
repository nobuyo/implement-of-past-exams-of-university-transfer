#include <stdio.h>

#define TRUE 1
#define FALSE 0

int func1(int b, int n) {
    if (n == 0)
        return 1;
    else
        return b * func1(b, n - 1);
}

int iseven(int n) {
    return n % 2 == 0 ? TRUE : FALSE;
}

int square(int n) {
    return n * n;
}

int halve(int n) {
    return n / 2;
}

int func2(int b, int n) {
    if (n == 0)
        return 1;
    if (iseven(n) == TRUE) {
        return func2(square(b), halve(n));
    }
    else {
        return b * func2(b, n - 1);
    }
}

int main(void) {
    // printf("%d\n", func1(2, 15));
    printf("%d\n", func2(2, 15));
}