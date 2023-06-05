#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int vertex;
    struct node *next;
};
struct node *graph[100];
int visited[100];
void init_graph()
{
    for(int i=0 ;i<100 ;i++)
    {
        visited[i]=0;
        graph[i]=NULL;
    }
}
void add_edge(int s ,int d)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    nn->vertex=d;
    nn->next=graph[s];
    graph[s]=nn;
    struct node *nu=(struct node *)malloc(sizeof(struct node));
    nu->vertex=s;
    nu->next=graph[d];
    graph[d]=nu;
}
void dfs(int source )
{
    visited[source]=1;
    printf("%d---",source);
    struct node *c=graph[source];
    while(c!=NULL)
    {
        int a =c->vertex;
        if(!visited[a])
        {
            dfs(a);
        }
        c=c->next;
    }
    
}
int main()
{
    init_graph();
    int d;
    printf("enter the number of vertices you want- ");
    scanf("%d",&d);
    for(int i=0 ;i<d ;i++)
    {
        int so ,de;
        printf("enter the source and destination vertex- ");
        scanf("%d %d",&so,&de);
        add_edge(so,de);
    }
    int s;
    printf("\nenter the source for depth first search- ");
    scanf("%d",&s);
    dfs(s);
}