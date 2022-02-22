#include <stdio.h>
#include <stdlib.h>


//реализовать обход в глубину с использованием стека си - или стандартного рекурсионного алгоритма DFS
struct node
{
    int vx;
    struct node* next;
};

struct node* crNode(int v);

struct Graph
{
    int numVH;
    int* vd;
    struct node** Lists; //Нам нужно сделать указатель на список ссылок
};

struct Graph* crGraph(int);
void addEdge(struct Graph*, int, int);
void pntGraph(struct Graph*);
void DFS(struct Graph*, int);


int main()
{

    struct Graph* graph = crGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    prtGraph(graph);

    DFS(graph, 2);

    return 0;
}

void DFS(struct Graph* graph, int vx) {
        struct node* List = graph->Lists[vx];
        struct node* temp = List;

        graph->visited[vx] = 1;
        printf("Visited %d \n", vx);

        while(temp!=NULL) {
            int connectedVx = temp->vx;

            if(graph->visited[connectedVx] == 0) {
                DFS(graph, connectedVx);
            }
            temp = temp->next;
        }
}


struct node* crNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vx = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* crGraph(int vs)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVH = vs;

    graph->Lists = malloc(vs * sizeof(struct node*));

    graph->visited = malloc(vs * sizeof(int));

    int i;
    for (i = 0; i < vs; i++) {
        graph->Lists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{

    struct node* newNode = crNode(dest);
    newNode->next = graph->Lists[src];
    graph->Lists[src] = newNode;

    newNode = crNode(src);
    newNode->next = graph->Lists[dest];
    graph->Lists[dest] = newNode;
}

void pntGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->numVH; v++)
    {
        struct node* temp = graph->Lists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vx);
            temp = temp->next;
        }
        printf("\n");
    }
}

===============================================================================================================
        //Моделируем робот поисковой системы. Дан готовый простой граф с циклическими связями. Нужно обойти этот граф двумя способами и подсчитать количество ссылок на каждый из узлов графа (полустепень захода).
//обход графа рекурсивной функцией (с подсчётом только смежных со стартовой вершин)
//обход графа по матрице смежности (с подсчётом всех вершин графа) В конце обхода вывести два получившихся списка всех узлов в порядке уменьшения количества ссылок на них.

===============================================================================================================
void recursive(node *root) //обход графа рекурсивной функцией (с подсчётом только смежных со стартовой вершин)
{
    if (root == NULL)
        return;
    recursive(root -> left);
    recursive(root -> right);
    if (root -> key)
        printf("%d ", root -> key);
}
void adj(node *root) //обход графа по матрице смежности (с подсчётом всех вершин графа)
{
    if (root == NULL)
        return;
    adj(root -> left);
    if (root -> key)
        printf("%d ", root -> key);
    adj(root -> right);
}
