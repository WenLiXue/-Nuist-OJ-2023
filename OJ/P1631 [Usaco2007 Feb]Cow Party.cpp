#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int from, to, v, nxt;
} edges[2][100100];

#define FOR(i, j, n) for (int i = j; i <= n; i++)

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = 10 * x + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int n, m, x;
int cnt[100100], head[2][100100], dis[2][1100], l[1100];
bool vis[1100];

inline void addEdge(int kind, int from, int to, int v) {
    cnt[kind]++;
    edges[kind][cnt[kind]].from = from;
    edges[kind][cnt[kind]].to = to;
    edges[kind][cnt[kind]].v = v;
    edges[kind][cnt[kind]].nxt = head[kind][from];
    head[kind][from] = cnt[kind];
}

void functionnnn(int kind) {
    FOR(i, 1, n) dis[kind][i] = 1e9;
    memset(vis, 0, sizeof(vis));
    int h = 0, t = 1;
    dis[kind][x] = 0;
    l[1] = x;
    while (h != t) {
        int now = l[++h];
        if (h == 1100) h = 0;
        vis[now] = false;
        for (int i = head[kind][now]; i; i = edges[kind][i].nxt) {
            if (dis[kind][now] + edges[kind][i].v < dis[kind][edges[kind][i].to]) {
                dis[kind][edges[kind][i].to] = dis[kind][now] + edges[kind][i].v;
                if (!vis[edges[kind][i].to]) {
                    vis[edges[kind][i].to] = true;
                    l[++t] = edges[kind][i].to;
                    if (t == 1100) t = 0;
                }
            }
        }
    }
}

int main() {
    n = read();
    m = read();
    x = read();
    FOR(i, 1, m) {
        int from = read();
        int to = read();
        int v = read();
        addEdge(0, from, to, v);
        addEdge(1, to, from, v);
    }
    functionnnn(0);
    functionnnn(1);
    int ans = 0;
    FOR(i, 1, n) ans = max(ans, dis[0][i] + dis[1][i]);
    cout<<ans<<endl;
    return 0;
}

