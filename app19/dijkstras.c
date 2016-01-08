#include <stdio.h>
typedef int bool;
int true = 1;
int false = 0;

int minKey(int key[], bool mset[], int v)
{
  int minIndex = 0;
  int min = 999,i;

  for( i = 0;i<v;i++)
  {
     if(mset[i]==false && key[i] < min) {
         minIndex = i;
         min = key[i];
     }
  }

  return minIndex;
}

void printDij(int parent[], int key[], int graph[10][10],int V)
{
    int i = 0;
    for(i =1;i<V;i++)
    {
        printf("%d -> %d : %d\n", parent[i],i, graph[i][parent[i]]);
    }
}

void dijMst(int graph[10][10],int V)
{
    int parent[V];
    bool mset[V];
    int dist[V];
    //set default values for key and parent

    int v,u;
     int i;
    for( i =0;i<V;i++)
    {
       mset[i] = false;
       dist[i] = 999;
       parent[i] = -1;
    }

    //set first node as visited
    dist[0] = 0;
    parent[0] = -1;

    for(i = 0;i<V;i++)
    {
        u=minKey(dist,mset,V);
        mset[u] = true;

        for(v=0;v<V;v++)
        {

            if( !mset[v] && graph[u][v] && dist[u] != 999 && dist[u]+graph[u][v] < dist[v]  ){
                    dist[v] = dist[u]+graph[u][v];
                    parent[v] = u;
            }

            /*if(graph[u][v] && mset[v]==false && graph[u][v] < key[v]) //first check whether node exists between two
            {
                 parent[v] = u;
                 key[v] = graph[u][v];
            }*/

        }

   }

//  printDij(parent,dist,9);
  printf("distance from the node: 0 \n");

  for(v=0;v<V;v++){
     printf(" 0 -> %d : %d \n",v, dist[v]);
  }
  printf("parent: \n");

  for(v=0;v<V;v++){
     printf("%d\n", parent[v]);
  }

}

int main()
{

    int prim[][] = {{0, 4,  0, 0, 0, 0, 0, 8, 0},
                    {4, 0,  8, 0, 0, 0, 0, 11,0},
                    {0, 8,  0, 7, 0, 4, 0, 0, 2},
                    {0, 0,  7, 0, 9, 14,0, 0, 0},
                    {0, 0,  0, 9, 0, 16, 0, 0, 0},
                    {0, 0,  4, 14,16, 0, 2, 0, 0},
                    {0, 0,  0, 0, 0, 2, 0, 1, 6},
                    {8, 11, 0, 0, 0, 0, 1, 0, 7},
                    {0, 0,  2, 0, 0, 0, 6, 7, 0}};
    dijMst(prim,9);
    return 0;
}
