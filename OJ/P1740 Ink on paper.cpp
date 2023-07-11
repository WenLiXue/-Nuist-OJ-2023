#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include<iostream>
#include<algorithm>
typedef long long ll ; 
using namespace std;
const int maxn=26*1e6;
struct edge
{
	int from,to;
	ll len;
}e[maxn];
struct node
{
	int ptr;
	ll x,y;
}point[5010];
bool cmp(edge a,edge b)//�ṹ��������� 
{
	return a.len<b.len;//����ֵΪ1�������ʲôʱ�����a<b 
}
int root[5010];//��ǰ����������ͨ���ĸ�
int findroot(int x)
{
	return root[x]==x?x:root[x]=findroot(root[x]);//·��ѹ�� 
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
	    {
	    	scanf("%lld%lld",&point[i].x,&point[i].y);
	    	root[i]=i;
		}
		int edgecnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)//��� 
			{
				edgecnt++;
				e[edgecnt].from=i;
				e[edgecnt].to=j;
				e[edgecnt].len=(point[i].x-point[j].x)*(point[i].x-point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y);
			}
		}
		int finaledge;//���湹����ͨ������������� 
		sort(e+1,e+edgecnt+1,cmp);//�Ȱ����еı߰���len�������� 
		int edgenub=0;
		for(int i=1;i<=edgecnt;i++)
		{
			int rf,rt;// root from,root to,�ֱ��ʾһ���ߵ�from��ĸ���to��ĸ� 
			rf=findroot(e[i].from);//���ú���������ã����ҽ�����·��ѹ�� 
			rt=findroot(e[i].to);
			if(rf!=rt)//������߲���һ����ͨ���� 
			{
				edgenub++;//������ͨ���ı�����һ 
				root[rt]=rf;
				finaledge=i;
				if(edgenub==n-1)//��n����������Ҫn-1���ߣ������ʱ������ 
					break;
			}
		}
		printf("%lld\n",e[finaledge].len);
	}
    return 0;
}
