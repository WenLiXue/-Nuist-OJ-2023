#include<bits/stdc++.h>
using namespace std;
//̰���㷨 ��ⲿ�ֿɷָ������
int N,T;  //N���Ա�ʾ�ɱ�������  T�������ɱ��������� 
double Value;  //���ڴ洢�ܼ�ֵ
struct NodeType{
	double w; //��Ʒ����
	double v;//��Ʒ��ֵ
	double p; //p=v/w  ����λ������Ӧ�ļ�ֵ
	bool operator<(const NodeType &s) const{
		return p>s.p;  //����p��ֵ��λ�� ���еݼ����� 
	} 
};
int main(){
	cin>>N>>T;
	NodeType A[N+1];int i; 
	for(i=1;i<=N;i++){
		cin>>A[i].w;cin>>A[i].v;
		A[i].p=A[i].v/A[i].w;
	}
	sort(A+1,A+N+1);//�Ӵ�С�ݼ�����
	Value=0.0;
	double weight=T; //���ڴ洢������װ�µ�ʣ������
	double x[N+1];  //ѡ����Ʒ����װ������
	memset(x,0,sizeof(x));
	i=1;
	while(A[i].w<weight){
		x[i]=1;
		weight-=A[i].w;
		Value+=A[i].v;
		i++;
	} 
	if(weight>0){  //���������������0 ˵��û��װ��
		x[i]=weight/A[i].w;
		Value+=x[i]*A[i].v;
	}
	printf("%.2lf\n",Value);
	return 0;	 
} 
