#include<bits/stdc++.h>
using namespace std;
//贪心算法 求解部分可分割背包问题
int N,T;  //N可以表示成背包数量  T可以理解成背包的容量 
double Value;  //用于存储总价值
struct NodeType{
	double w; //物品重量
	double v;//物品价值
	double p; //p=v/w  即单位重量对应的价值
	bool operator<(const NodeType &s) const{
		return p>s.p;  //按照p价值单位比 进行递减排序 
	} 
};
int main(){
	cin>>N>>T;
	NodeType A[N+1];int i; 
	for(i=1;i<=N;i++){
		cin>>A[i].w;cin>>A[i].v;
		A[i].p=A[i].v/A[i].w;
	}
	sort(A+1,A+N+1);//从大到小递减排序
	Value=0.0;
	double weight=T; //用于存储背包能装下的剩余容量
	double x[N+1];  //选择物品与否的装入数组
	memset(x,0,sizeof(x));
	i=1;
	while(A[i].w<weight){
		x[i]=1;
		weight-=A[i].w;
		Value+=A[i].v;
		i++;
	} 
	if(weight>0){  //如果余下重量大于0 说明没有装满
		x[i]=weight/A[i].w;
		Value+=x[i]*A[i].v;
	}
	printf("%.2lf\n",Value);
	return 0;	 
} 
