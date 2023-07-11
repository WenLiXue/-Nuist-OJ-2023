#include<bits/stdc++.h>
using namespace std;
int a[1001];
int n;
int sum=0;
int main() {

	while(cin>>n) {
		sum=0;
		int max=-100;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			if(a[i]>max)
				max=a[i];
			sum+=a[i];
		}
		if(max>=sum-max)
			printf("%.1lf\n",(sum-max)*1.0);
		else
			printf("%.1lf\n",sum*1.0/2);
	}
	return 0;
}

