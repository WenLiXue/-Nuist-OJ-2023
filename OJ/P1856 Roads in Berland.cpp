#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, m[304][304];
ll ans[304];
int main(){
    cin >> n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) scanf("%d", &m[i][j]);
    cin >> k;
    int u, v, val;
    for(int d=1;d<=k;++d){
        scanf("%d %d %d", &u, &v, &val);
        if(val < m[u][v]){
            m[u][v] = m[v][u] = val;
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j) m[i][j] = m[j][i] = min(m[i][j], m[i][u]+m[u][j]);
            }
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j) m[i][j] = m[j][i] = min(m[i][j], m[i][v]+m[v][j]);
            }
        }
        ll sum = 0;
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                sum += m[i][j];
            }
        }
        ans[d] = sum;
    }
    for(int i=1;i<k;++i) printf("%lld ", ans[i]);
    printf("%lld\n", ans[k]);
    return 0;
}
