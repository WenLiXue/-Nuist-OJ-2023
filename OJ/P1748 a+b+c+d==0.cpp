#include<iostream>
#include<map>
using namespace std;
int n,a,b,c,d;
int T;
int sum=0;
int arr[3000][4];
int temp[3000][2];
int main()
{
	cin>>T;
	while(T--)
	{
		sum=0;
			map <int ,int >m;
		map <int ,int>::iterator iter;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				m[arr[i][0]+arr[j][1]]++;
			}
		}
			for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(m[-1*(arr[i][2]+arr[j][3])]>0)
					sum+=m[-1*(arr[i][2]+arr[j][3])];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
 } 
