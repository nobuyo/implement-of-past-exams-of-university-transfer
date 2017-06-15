#include <stdio.h>

int count;

// (1)
void swap(int i, int j, int array[]) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

// (2)
int max_position(int n, int array[]) {
    count++;
    if (n > 1) {
        int p = max_position(n - 1, array);
        if (array[n - 1] < array[p]) {
            return max_position(n - 1, array);
        } else {
            return n - 1;
        }
    }
    return 0;
}

// (6)
int max_position2(int n, int array[]) {
    count++;
    if (n > 1) {
        int p = max_position(n - 1, array);
        if (array[n - 1] < array[p]) {
            return p;
        } else {
            return n - 1;
        }
    }
    return 0;
}

void s(int n, int array[]) {
    if (n > 1) {
        swap(n - 1, max_position(n, array), array);
        s(n - 1, array);
    }
}

// (6)
void s2(int n, int array[]) {
    if (n > 1) {
        swap(n - 1, max_position2(n, array), array);
        s(n - 1, array);
    }
}

void r(int n, int array[]) {
    if (n > 1) {
        swap(0, max_position(n, array), array);
        r(n - 1, array + 1);
    }
}

int main(void) {
    int a3[] = {3, 2, 1};
    int a10[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a10_2[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a10_3[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    count = 0;

    // (3)
    max_position(3, a3);
    printf("%d\n", count);

    count = 0;
    s(10, a10);

    printf("A=%d\n", a10[3]);
    printf("B=%d\n", a10[9]);
    printf("C=%d\n", count);

    // (5)
    r(10, a10_2);
    printf("D=%d\n", a10_2[3]);
    printf("E=%d\n", a10_2[9]);

    // (6)
    count = 0;
    s2(10, a10_3);
    printf("C=%d\n", count);

    return 0;
}
