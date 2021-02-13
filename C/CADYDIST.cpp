#include<bits/stdc++.h>
using namespace std;

 int main(){
 	int n;
 	while(1){
 		cin>>n;
 		int a[n],b[n];
 		if(n==0)break;
 		for(int i=0;i<n;i++)cin>>a[i];
 		for(int i=0;i<n;i++)cin>>b[i];
 		sort(a,a+n);
 		sort(b,b+n);
 		int ans=0;
 		for(int i=0;i<n;i++)ans+=a[i]*b[n-1-i];
 		cout<<ans<<endl;
	 }
 	return 0;
 }
