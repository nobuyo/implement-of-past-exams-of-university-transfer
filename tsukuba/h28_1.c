#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 10

struct kv {
    char *key;
    int value;
};

struct node {
    int end_of_key;
    int value;
    struct node *next_char[26];
};

struct kv kv_array[N];

int search_array(char *key) {
    int start = 0;
    int end = N - 1;
    int middle;
    while (start <= end) {
        middle = (start + end) / 2;
        if (strcmp(kv_array[middle].key, key) == 0) {
            return kv_array[middle].value;
        } else if (strcmp(kv_array[middle].key, key) < 0) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    return -1;
}

int numchar(char c) {
    return (int)c - 96;
}

int search_tree(struct node *root, char *key) {
    int i, len;
    len = strlen(key);
    struct node *n = root;
    for (i = 0; i < len; i++) {
        printf("%c\n", key[i]);
        if (n->next_char[numchar(key[i]) - 1] == NULL) {
            return -1;
        } else {
            n = n->next_char[numchar(key[i]-1)];
        }
    }
    if (n->end_of_key == 1) {
        return n->value;
    } else {
        return -1;
    }
}

int main(void) {
    int i,j,k,l;
    struct node *root, *n;

    // initialize for array
    char str_list[N][10] = {
        "ant", "anyway", "apart", "appear", "apple", "bad", "bag", "below", "cry", "cut"
    };

    for (int i = 0; i < N; i++)
    {
        kv_array[i].key = str_list[i];
        kv_array[i].value = (i+1)*10;
    }

    for (int i = 0; i < N; i++)
    {
        printf("kv_array[%d] = %s: %d\n",i, kv_array[i].key, kv_array[i].value);
    }

    // initialize for tree

    root = (struct node *)malloc(sizeof(struct node));

    root->end_of_key = 0;
    root->value = 0;

    for (k=0; k<26; k++) {
        root->next_char[k] = NULL;
    }

    for (i=0; i<N; i++) {
        l = strlen(str_list[i]);
        j = 0;
        n = root;

        while (str_list[i][j] != '\0') {
            // printf("%c, %d\n", str_list[i][j], numchar(str_list[i][j]));
            if (i == 0 || n->next_char[numchar(str_list[i][j]) - 1] == NULL) {
                n->next_char[numchar(str_list[i][j]) - 1] = (struct node *)malloc(sizeof(struct node));
                // for (k='a'; k<='z'; k++) {
                //     printf("%c, %p ", k, n->next_char[numchar(k)-1]);
                // }
                // putchar('\n');
                n = n->next_char[numchar(str_list[i][j]) - 1];
                n->end_of_key = 0;
                n->value = 0;
                for (k=0; k<26; k++) {
                    n->next_char[k] = NULL;
                }
            }
            else {
                // for (k='a'; k<='z'; k++) {
                //     printf("%c, %p ", k, n->next_char[numchar(k)-1]);
                // }
                n = n->next_char[numchar(str_list[i][j]) - 1];
            }

            j++;
        }
        n->end_of_key = 1;
        n->value = (i+1)*10;
    }

    printf("search_array '%s': %d\n", "bad", search_array("bad"));
    printf("search_tree '%s': %d\n",  "anyway", search_tree(root ,"anyway"));
    // printf("search 'bad': %d", search_array("bad");
}




