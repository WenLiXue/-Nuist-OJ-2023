#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define LOOP(i, n) for(int i=0; i<(n); ++i)
#define FOR1(i,a,n) for(int i=(a);i<=(n);++i)
#define FOR2(i,a,n) for(int i=(a);i<(n);++i)
#define FOR3(i,a,n) for(int i=(a);i>=(n);--i)
#define FOR4(i,a,n) for(int i=(a);i>(n);--i)
#define MEM(i,a) memset(i,a,sizeof(i))
#include <queue>
#include<bits/stdc++.h>
#define READ(a) a=getInt()
#define PRINT(a) printf("%d", a)
#define DBG(x) cout << #x << " = " << x << endl
#define PRINTARR(a, n, m) LOOP(aaa, n) { LOOP(bbb, m) cout << a[aaa][bbb]; cout << endl; }
using namespace std;
inline const int getInt() {
    int r=0, k=1;
    char c=getchar();
    for(; c<'0'||c>'9'; c=getchar())
        if(c=='-') k=-1;
    for(; c>='0'&&c<='9'; c=getchar())
        r=r*10+c-'0';
    return k*r;
}

inline const int max(const int &a, const int &b) {
    return a>b?a:b;
}

inline const int min(const int &a, const int &b) {
    return a<b?a:b;
}

const int N=2005, M=10005;

struct Edge {
    int x, y, w;
} edges[M];

int parent[N], n, m;

bool cmp(const Edge &a, const Edge &b) {
    return a.w<b.w;
}

int findParent(int x) {
    return x==parent[x] ? x : parent[x]=findParent(parent[x]);
}

int main() {
    READ(n);
    READ(m);
    FOR1(i, 1, m) {
        edges[i].x=getInt();
        edges[i].y=getInt();
        edges[i].w=getInt();
    }
    FOR1(i, 1, n) parent[i]=i;
    sort(edges+1, edges+1+m, cmp);
    int ans=0;
    FOR1(i, 1, m) {
        int fx=findParent(edges[i].x), fy=findParent(edges[i].y);
        if(fx!=fy) {
            parent[fx]=fy;
            ans=max(ans, edges[i].w);
        }
    }
    PRINT(ans);
    return 0;
}

