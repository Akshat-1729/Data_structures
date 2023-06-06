#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct node {
    int vertex;
    struct node *next;
} node;

node *graph[MAX_VERTICES];
int visited[MAX_VERTICES];

void init_graph() {
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        graph[i] = NULL;
        visited[i] = 0;
    }
}

void add_edge(int u, int v) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->vertex = v;
    new_node->next = graph[u];
    graph[u] = new_node;

    new_node = (node *)malloc(sizeof(node));
    new_node->vertex = u;
    new_node->next = graph[v];
    graph[v] = new_node;
}

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    node *adj_list = graph[v];
    while (adj_list != NULL) {
        int adj_vertex = adj_list->vertex;
        if (!visited[adj_vertex]) {
            dfs(adj_vertex);
        }
        adj_list = adj_list->next;
    }
}

int main() {
    init_graph();

    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(1, 3);
    add_edge(2, 3);
    add_edge(3, 4);
    add_edge(4, 5);

    printf("Depth First Search starting from vertex 0:\n");
    dfs(0);
    printf("\n");

    return 0;
}