#include <stdio.h>

void exch(int a[], int i, int j) {
    int tmp;
    tmp = a[i]; a[i] = a[j]; a[j] = tmp;
}

int partition(int a[], int p, int r) {
    int i, j, x;
    x = a[r];
    i = p - 1;
    for (j = p; j < r; j++)
        if (a[j] <= x) {
            i = i + 1;
            exch(a, i , j);
            printf("i=%d, j=%d\n", i, j);
        }
    exch(a, r, i+1);
    return i + 1;
}

void sort(int a[], int p, int r) {
    int q;
    if (p < r) {
        q = partition(a, p, r);
        sort(a, p, q-1);
        sort(a, q, r);
    }
}

int select(int a[], int p, int r, int i) {
    int q, k;
    printf("p == r?\n");
    if (p == r) {
        return a[p]; /* 行 (B) */ 
    }
    q = partition(a, p, r);
    k = q - p;
    if (i == k) return a[q];
    else if (i < k) return select(a, p, q - 1, i);
    else return select(a, q + 1, r, i - (k + 1));
}

int main(void) {
    int a1[6] = {5, 10, 7, 12, 8, 9};
    int a5[5] = {8, 7, 6, 5, 4};
    // int a5[5] = {4, 3, 2, 1, 0};
    // int a1[6] = {5, 10, 7, 12, 8, 9};
    int i;

    // partition(a1, 0, 5);
    // sort(a1, 0, 5);
    select(a5, 0, 4, 2);
    // for (i = 0; i < 6; i++) {
    //     printf("%d\n", a1[i]);
    // }

}