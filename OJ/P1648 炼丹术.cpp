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
		pre[i]=i;//��ʼ��������
	}
	for(int i=1;i<=n;++i) {
		int u=find(i), v=find(a[i]);//ͨ��ǰ׺������²��鼯����ѯ�����н���·��ѹ��
		if(u!=v)pre[u]=v;			//�ϲ����������
	}
	int cnt=0;
	for(int i=1;i<=n;++i) {			//��¼��ͬ���ϸ���
		if(pre[i]==i) cnt++;
	}
	printf("%d",pow(cnt)-1);
	return 0;	
}

