#include<iostream>
using namespace std;
const int MAXN=1000005;
const int INF=0x3f3f3f3f;
const int mod=998244353;
int flag[10005];            	//堆空间，默认初始化全是0，等价于 int flag[10005]={0}; 
								//flag值为0表示没水塘，为1表示有水塘
int main(){
	int n,m,k;               	//n，m，k分别代表路径的长度，积水的个数以及wzy一次最远可以跨多远
	int num; 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){ 		//将有水塘的点赋值为1 
		cin>>num;
		flag[num]=1;            
	}
	int left=0,right=1,count=0; //count为需要踩水塘的次数 
	int begin=1,end=n;          //重新定义begin，end变量，方便分类讨论 
	
	//若第一点有水塘 
	if(flag[1]==1){
		for(int i=2;i<=n;i++){	//找到第二个是水塘的点 
			if(flag[i]==0){
				right=i;
				break;
			}
		} 
		count+=(right-1-1)/k+1;
		begin=right;
	}
	
	//如果最后一个点有水塘
	if(flag[n]==1){
		for(int i=n-1;i>=1;i--){//找到倒数第二个是水塘的点 
			if(flag[i]==0){
				left=i;
				break;
			}
		}
		count+=(n-left-1)/k+1;
		end=left;
	} 
	
	//此时起点和终点都没有水塘 
	if(begin!=end){
		for(int i=begin;i<=end;i++){
			if(flag[i]==0){  
				left=i;
				int j;
				for(j=i+1;j<=end;j++){
					if(flag[j]==0){
						right=j;
						break;
					}
				}
				if(j>end) break;   //不写这句会陷入死循环！ 
				count+=(right-left-1)/k;
			}
			i=right-1;
		}
	}
	
	//输出结果 
	cout<<count<<endl;
	
	return 0;
}
