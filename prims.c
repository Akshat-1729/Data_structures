#include <stdio.h>
#include <stdbool.h>
#define V 6
#define INF 99999
int parent[V];
int key[V];
bool mstset[V];
int minkey(){
    int min=INF;
    int min_index;
    for(int v=0;v<V;v++){
        if(mstset[v]==false && key[v]<min){
            min_index=v;
        }
    }
    return min_index;
}
void print( int graph[][V])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[parent[i]][i]);
}
void prim(int graph [][V]){
    for(int v=0;v<V;v++){
        key[v]=INF;
        mstset[v]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<V;i++){
        int u=minkey();
        mstset[u]=true;
        for(int v=0;v<V;v++){
            if(graph[u][v] && mstset[v]==false && graph[u][v]<key[v]){
                parent[v]=u;
                key[v]=graph[u][v];
            }
            if(graph[v][u] && mstset[v]==false && graph[v][u]<key[v]){
                parent[v]=u;
                key[v]=graph[v][u];
            }
        }
    }
    print(graph);
}
int main(){
    int graph[V][V] = {{0, 4, 1, 0, 0, 0}, //0
                       {0, 0, 8, 0, 0, 0}, //1
                       {0, 0, 0, 7, 0, 0}, //2
                       {0, 0, 0, 0, 9, 2}, //3
                       {0, 0, 0, 0, 0, 10},//4
                       {0, 0, 0, 0, 0, 0}};//5

    prim(graph);

    return 0;
}