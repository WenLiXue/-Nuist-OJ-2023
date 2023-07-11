#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;int a[n],b[n],ans=0;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int j=0;j<n;j++) cin>>b[j];
	sort(a,a+n);sort(b,b+n);
	int lefta=0,leftb=0,righta=n-1,rightb=n-1;
	while(lefta<=righta){
		if(a[righta]>b[rightb]){
			ans+=200;righta--;rightb--;
		}
		else if(a[righta]<b[rightb]){
			ans-=200;lefta++;rightb--;
		}
		else{
			if(a[lefta]>b[leftb]){
				ans+=200;lefta++;leftb++;
			}
			else{
				if(a[lefta]<b[rightb]) ans-=200;lefta++;rightb--;
			}
		}
	}
	cout<<ans<<endl;return 0;
}
