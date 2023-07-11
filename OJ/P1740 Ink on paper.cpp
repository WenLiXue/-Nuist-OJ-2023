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
bool cmp(edge a,edge b)//结构体的排序函数 
{
	return a.len<b.len;//返回值为1定义的是什么时候代表a<b 
}
int root[5010];//当前结点的所在连通集的根
int findroot(int x)
{
	return root[x]==x?x:root[x]=findroot(root[x]);//路径压缩 
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
			for(int j=i+1;j<=n;j++)//存边 
			{
				edgecnt++;
				e[edgecnt].from=i;
				e[edgecnt].to=j;
				e[edgecnt].len=(point[i].x-point[j].x)*(point[i].x-point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y);
			}
		}
		int finaledge;//储存构成连通集的最长的那条边 
		sort(e+1,e+edgecnt+1,cmp);//先把所有的边按照len升序排序 
		int edgenub=0;
		for(int i=1;i<=edgecnt;i++)
		{
			int rf,rt;// root from,root to,分别表示一个边的from点的根和to点的根 
			rf=findroot(e[i].from);//调用函数即可求得，并且进行了路径压缩 
			rt=findroot(e[i].to);
			if(rf!=rt)//如果二者不在一个联通集中 
			{
				edgenub++;//构成连通集的边数加一 
				root[rt]=rf;
				finaledge=i;
				if(edgenub==n-1)//把n个点连起来要n-1条边，满足的时候跳出 
					break;
			}
		}
		printf("%lld\n",e[finaledge].len);
	}
    return 0;
}
