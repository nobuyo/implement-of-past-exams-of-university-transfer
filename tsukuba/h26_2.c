#include <stdio.h>
#include <stdlib.h>

int cnt = 0;

typedef struct node {
    int adjacent;
    struct node *next;
} node;

void visit(int id, int visited[], node nodes[]) {
    node *n;

    cnt++;

    if (visited[id]) return;

    visited[id] = 1;
    for (n = &nodes[id]; n->adjacent != -1; n = n->next) {
        visit(n->adjacent, visited, nodes);
    }
}

int is_connected(int nnode, node nodes[]) {
    int i, *visited;
    visited = (int *)malloc(sizeof(int) * nnode);
    for (i = 0; i < nnode; i++) {
        visited[i] = 0;
    }

    visit(0, visited, nodes);

    for (i = 0; i < nnode; i++) {
        if (visited[i] == 0) return 0;
    }
    return 1;
}

int is_euler(int nnode, node nodes[]) {
    int i, j, count = 0;
    node *n;
    if (!is_connected(nnode, nodes))
        return 0;
    for (i = 0; i < nnode; i++) {
        n = nodes[i].next;
        j = 0;
        while (n != NULL) {
            j++;
            n = n->next; 
        }

        // (4)
        if (j % 2 == 1) {
            count++;
        }
    }
    return count == 0 || count == 2;
}

void create_graph(int nnode, node nodes[], int c[][4]) {
    int i, j;
    node *n;

    for(i = 0; i < nnode; i++) {
        for (j = 0, n = &nodes[i]; c[i][j] != -1; j++, n = n->next) {
            n->adjacent = c[i][j];
            n->next = (node *)malloc(sizeof(node));
        }
        n->next = NULL;
        n->adjacent = -1;
    }
}

int main(void) {
    node g1[4], g2[4], g3[5];
    int g1_ary[4][4] = {
        {1, -1, -1, -1},
        {3, 2, 0, -1},
        {3, 1, -1, -1},
        {2, 1, -1, -1}
    };

    int g2_ary[4][4] = {
        {2, 1, -1, -1},
        {2, 0, -1, -1},
        {1, 0, -1, -1},
        {-1, -1, -1, -1}
    };

    int g3_ary[5][4] = {
        {1, -1, -1, -1},
        {3, 2, 0, -1},
        {4, 3, 1, -1},
        {2, 1, -1, -1},
        {2, -1, -1, -1}
    };

    create_graph(4, g1, g1_ary);
    create_graph(4, g2, g2_ary);
    create_graph(5, g3, g3_ary);

    // (1)
    printf("%d\n", is_connected(4, g1));
    printf("%d\n", is_connected(4, g2));
    printf("%d\n", is_connected(5, g3));

    // (3)
    printf("cnt = %d\n", cnt);

    printf("%d\n", is_euler(4, g1));
    printf("%d\n", is_euler(4, g2));
    printf("%d\n", is_euler(5, g3));

    return 0;
}
