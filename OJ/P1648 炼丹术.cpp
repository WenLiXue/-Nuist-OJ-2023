#include<cstdio>
#include<iostream>
const int MAXN=1000005;
const int INF=0x3f3f3f3f;
const int mod=998244353;

using namespace std;

int pre[MAXN], a[MAXN];

int find(int x) {
	while(x!=pre[x])x=pre[x]=pre[pre[x]];
	return x;
}
int pow(int n) {
	int ans=1,base=2;
	for(int i=1;i<=n;++i) {
		ans=(ans*base)%mod;
	}
	return ans;
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%d",&a[i]);
		pre[i]=i;//初始化查数组
	}
	for(int i=1;i<=n;++i) {
		int u=find(i), v=find(a[i]);//通过前缀数组更新并查集，查询过程中进行路径压缩
		if(u!=v)pre[u]=v;			//合并相关联集合
	}
	int cnt=0;
	for(int i=1;i<=n;++i) {			//记录不同集合个数
		if(pre[i]==i) cnt++;
	}
	printf("%d",pow(cnt)-1);
	return 0;	
}

