#include<iostream>
using namespace std;
const int MAXN=1000005;
const int INF=0x3f3f3f3f;
const int mod=998244353;
int flag[10005];            	//�ѿռ䣬Ĭ�ϳ�ʼ��ȫ��0���ȼ��� int flag[10005]={0}; 
								//flagֵΪ0��ʾûˮ����Ϊ1��ʾ��ˮ��
int main(){
	int n,m,k;               	//n��m��k�ֱ����·���ĳ��ȣ���ˮ�ĸ����Լ�wzyһ����Զ���Կ��Զ
	int num; 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){ 		//����ˮ���ĵ㸳ֵΪ1 
		cin>>num;
		flag[num]=1;            
	}
	int left=0,right=1,count=0; //countΪ��Ҫ��ˮ���Ĵ��� 
	int begin=1,end=n;          //���¶���begin��end����������������� 
	
	//����һ����ˮ�� 
	if(flag[1]==1){
		for(int i=2;i<=n;i++){	//�ҵ��ڶ�����ˮ���ĵ� 
			if(flag[i]==0){
				right=i;
				break;
			}
		} 
		count+=(right-1-1)/k+1;
		begin=right;
	}
	
	//������һ������ˮ��
	if(flag[n]==1){
		for(int i=n-1;i>=1;i--){//�ҵ������ڶ�����ˮ���ĵ� 
			if(flag[i]==0){
				left=i;
				break;
			}
		}
		count+=(n-left-1)/k+1;
		end=left;
	} 
	
	//��ʱ�����յ㶼û��ˮ�� 
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
				if(j>end) break;   //��д����������ѭ���� 
				count+=(right-left-1)/k;
			}
			i=right-1;
		}
	}
	
	//������ 
	cout<<count<<endl;
	
	return 0;
}
