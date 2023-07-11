#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1010;
struct node//三元组结构
{
    int id;//工作编号
    int ab;//在哪个机器
    int times;//时间
    bool operator < (node tmp)const
    {
        return times<tmp.times;//按时间从小到大排序
    }
};
void johnson(node s[],int n,int a[],int b[],int c[])//Johnson算法 生成三元组表s
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]>b[i])
        s[i].ab=2,s[i].times=b[i];
        else
        s[i].ab=1,s[i].times=a[i];
        s[i].id=i;
    }
    sort(s+1,s+n+1);//按times从下到大排序
    int l=0,r=n+1;
    for(int i=1;i<=n;i++)//生成加工顺序
    {
        if(s[i].ab==1)
        c[++l]=s[i].id;
        if(s[i].ab==2)
        c[--r]=s[i].id;
    }
}
int main()
{
	int n;
	while(cin>>n){
		int a[maxn],b[maxn],c[maxn],t[maxn];
		node s[maxn];
		for(int i=1;i<=n;i++)
	    cin>>a[i];
	    for(int i=1;i<=n;i++)
	    cin>>b[i];
	    johnson(s,n,a,b,c);
	    for(int i=1;i<=n;i++)//计算最少时间 
	    t[i]=t[i-1]+a[c[i]]; 
	    int ans=t[1]+b[c[1]];
	    for(int i=2;i<=n;i++)
	    ans=max(ans,t[i])+b[c[i]];
	    cout<<ans<<endl;//答案	
	}
    return 0;
}
