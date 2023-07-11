#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#define PI 3.14159
#define MAX_VALUE 100
#define TRUE 1
#define FALSE 0
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX_N = 100+5, INF = 0x3f3f3f3f;
int graph[MAX_N][MAX_N];

void floydWarshall(int numVertices) {
    for(int k = 1; k <= numVertices; k++)
        for(int i = 1; i <= numVertices; i++)
            for(int j = 1; j <= numVertices; j++)
                if (graph[i][k] != INF && graph[k][j] != INF)
                    graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
}

int main() {
    int numVertices, numEdges, numQueries, caseNum = 0;
    while(scanf("%d%d%d",&numVertices,&numEdges,&numQueries) == 3 && numVertices){
        memset(graph, INF, sizeof(graph));
        for(int i = 0; i < numEdges; i++){
            int u, v, d;
            scanf("%d%d%d",&u,&v,&d);
            graph[u][v] = graph[v][u] = d;
        }
        floydWarshall(numVertices);
        printf("Case #%d\n", ++caseNum);
        while(numQueries--){
            int u, v;
            scanf("%d%d",&u,&v);
            if(graph[u][v] == INF) printf("no path\n");
            else printf("%d\n",graph[u][v]);
        }
    }
    return 0;
}

