#include <stdio.h>
#include <limits.h>

int V;

int minKey(int key[], int mstSet[])
{
   int min = INT_MAX,v, min_index;

   for (v = 0; v < V; v++)
     if (mstSet[v] == 0 && key[v] < min)
         min = key[v], min_index = v;

   return min_index;
}

int printMST(int parent[], int n, int graph[V][V])
{
int i;
   printf("Edge   Weight\n");
   for (i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{
     int parent[V],v,i,count,u;
     int key[V];
     int mstSet[V];


     for ( i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

       key[0] = 0;
     parent[0] = -1;

     for ( count = 0; count < V-1; count++)
     {
         u = minKey(key, mstSet);

        mstSet[u] = 1;

        for (v = 0; v < V; v++)

          if (graph[u][v] && mstSet[v] == 0 && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }

   printMST(parent, V, graph);
}

int main()
{
        int i,j;
        printf("enter number of vertices: ");
        scanf("%d",&V);
        int graph[V][V];
        for(i=0;i<V;i++)
        {
                for(j=0;j<V;j++)
                {
                        scanf("%d",&graph[i][j]);
                }
        }
    primMST(graph);
    return 0;
}
