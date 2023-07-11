#include <bits/stdc++.h>
#define INF 2147483647
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
int head[(int)1e6+10], cnt;
int dist[(int)1e6+10], visited[(int)1e6+10];
int n, m, start;
#include <algorithm>
#include <cstdio>
#include <cstring>
#define LOOP(i, n) for(int i=0; i<(n); ++i)
#define FOR1(i,a,n) for(int i=(a);i<=(n);++i)
#define FOR2(i,a,n) for(int i=(a);i<(n);++i)
#define FOR3(i,a,n) for(int i=(a);i>=(n);--i)
#define FOR4(i,a,n) for(int i=(a);i>(n);--i)
#define MEM(i,a) memset(i,a,sizeof(i))


void initialize()
{
    for(int i = 1; i <= n; i++)
        dist[i] = INF;
}

struct Edge{
    int to;
    int weight;
    int next;
} edges[(int)1e6+10];

struct Node{
    int w;
    int now;
    bool operator <(const Node &x) const
    {
        return w > x.w;
    }
};

priority_queue<Node> pq;

void addEdge(int u, int v, int w)
{
    edges[++cnt].to = v;
    edges[cnt].weight = w;
    edges[cnt].next = head[u];
    head[u] = cnt;
}

void dijkstra()
{
    for(int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[start] = 0;
    pq.push((Node){0, start});
    while(!pq.empty()){
        Node x = pq.top();
        pq.pop();
        int u = x.now;
        if(visited[u]) continue;
        visited[u] = 1;
        for(int i = head[u]; i; i = edges[i].next){
            int v = edges[i].to;
            if(dist[v] > dist[u] + edges[i].weight){
                dist[v] = dist[u] + edges[i].weight;
                pq.push((Node){dist[v], v});
            }
        }
    }
}

int main()
{
    int target;
    cin >> n >> m >> start >> target;
    initialize();
    for(int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        addEdge(x, y, z);
        addEdge(y, x, z);
    }
    int pos = start;
    dist[pos] = 0;
    while(visited[pos] == 0){
        int minDist = INF;
        visited[pos] = 1;
        for(int i = head[pos]; i != 0; i = edges[i].next){
            if(!visited[edges[i].to] && (dist[edges[i].to] > dist[pos] + edges[i].weight))
                dist[edges[i].to] = dist[pos] + edges[i].weight;
        }
        for(int i = 1; i <= n; i++)
            if(dist[i] < minDist && visited[i] == 0){
                minDist = dist[i];
                pos = i;
            }
    }
    cout << dist[target] << endl;
    return 0; 
}

