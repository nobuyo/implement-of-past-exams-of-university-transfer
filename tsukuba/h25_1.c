#include <stdio.h>

int f1(int x, int y) {
    int r;
    for (r = 0; y > 0; y--)
        r = r + x;
    return r; 
}

int f2(int x, int y) {
    int r;
    for (r = x; y > 0; y--) r++; /* 文1*/
    return r;
}

int f3(int x, int y) {
    int r;
    for (r = 0; y > 0; y--) {
        r = f2(r, x);
        printf("f2() called\n");
    }
    return r;
}

int f4(int x, int y) {
    int r;
    for (r = 0; y > 0; y = y / 2) {
        if (y % 2 == 1) {
            r = r + x; /* 文 2 */
            // printf("sentence 2\n");
        }
        x = x * 2; /* 文 3 */
        // printf("sentence 3\n");
    }
    return r;
}

int g(int x, int y, int r) {
    if (y == 0) {
        return r;
    }
    else {
        return g(x, y-1, x+r);
    }
}

int f5(int x, int y) {
    return g(x, y, 0);
}

int f6(int x, int y) {
    if (y == 0) {
        return 0;
    }
    else if (y % 2 == 1) {
        return f6(x*2, y/2) + x;
    }
    else {
        return f6(x*2, y/2);
    }
}

int main(void) {
    printf("f1(3,5) %d\n",f1(3,5));
    printf("f1(5,3) %d\n",f1(5,3));
    printf("f2(3,5) %d\n",f2(3,5));
    printf("f3(3,5) %d\n",f3(3,5));
    printf("f4(3,5) %d\n",f4(3,5));
    // printf("f4(11,33) %d\n",f4(11,33));
    printf("f5(3,5) %d\n",f5(3,5));
    printf("f6(3,5) %d\n",f6(3,5));
}