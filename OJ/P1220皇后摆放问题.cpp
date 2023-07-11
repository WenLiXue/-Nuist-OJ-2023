#include<bits/stdc++.h>
using namespace std;
const int N =15;
int col[N],d1[N*2],d2[N*2];
int b[N];
int a[N];
int cnt =0;
int n=8;
int total = 0;
void dfs(int row)
{
	if(row>n)
	{
		int temp =0;
			for(int i=1;i<=n;i++)	
			{
				if(b[i]==a[i])temp++;
			}
			if(temp==total)cnt++;
			return;
	
	}
	for(int j=1;j<=n;j++)
	{
		if(!col[j]&&!d2[row-j+n]&&!d1[j+row])
		{
			b[row] = j;
			col[j]=d2[row-j+n]=d1[j+row]=1;
			dfs(row+1);
			col[j]=d2[row-j+n]=d1[j+row]=0;
		}
	}
}
int main()
{
	int t;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>t;
			if(t==1)
				a[i]=j,total++;
		 } 
	dfs(1);
	cout<<cnt<<endl;
	return 0;
}
