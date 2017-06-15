#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N    100

int cnt = 0;

struct dict_list {
    struct dict_list *next;
    char *name;
};

struct dict_list *bucket[N];

int h1(char *str) {
    return *str % N;
}

int h2(char *str) {
    return (str[0] + str[1]) % N;
}

int h3(char *str) {
    unsigned int i, v;
    int l = strlen(str);

    v = 0;
    for (i = 0; i < l; i++) {
        v = v + (str[i] << ((i * 7) % 31));
    }
    return v % N;
}

int search1(char *str) {
    struct dict_list *elem;
    int i;
    i = h1(str);
    elem = bucket[i];
    while (elem) {
        int cmp_result = strcmp(elem->name, str);
        cnt++;
        if (!cmp_result) return -1;
        elem = elem->next;
    }
    return i;
}

int search2(char *str) {
    struct dict_list *elem;
    int i;
    i = h2(str);
    elem = bucket[i];
    while (elem) {
        int cmp_result = strcmp(elem->name, str);
        cnt++;
        if (!cmp_result) return -1;
        elem = elem->next;
    }
    return i;
}

void insert1(char *str) {
    struct dict_list *new;
    int i;

    i = search1(str);
    if (i < 0) return;
    new = malloc(sizeof(struct dict_list));
    new->next = bucket[i];
    new->name = str;
    bucket[i] = new;
}

void insert2(char *str) {
    struct dict_list *new;
    int i;

    i = search2(str);
    if (i < 0) return;
    new = malloc(sizeof(struct dict_list));
    new->next = bucket[i];
    new->name = str;
    bucket[i] = new;
}

void display(void) {
    int i;
    struct dict_list *elem;

    for (i = 0; i < N; i++) {
        elem = bucket[i];
        if (elem == NULL) continue;
        printf("bucket[%d]->", i);
        while (elem) {
            printf("[%s]->", elem->name);
            elem = elem->next;
        }
        printf("[]\n");
    }
}

int main(void) {
    // (2)
    insert1("hydrogen");
    insert1("helium");
    insert1("lithium");
    insert1("berylium");
    insert1("boron");
    insert1("carbon");
    insert1("nitrogen");
    insert1("oxygen");
    insert1("fluorine");
    insert1("neon");

    cnt = 0;

    display();

    // (3)
    insert1("natrium");
    printf("h1: strcmp() called for %d times.\n", cnt);
    // insert2("natrium");
    // printf("h2: strcmp() called for %d times.\n", cnt);

    return 0;
}
