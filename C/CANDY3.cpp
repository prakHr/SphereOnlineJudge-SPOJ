#include<bits/stdc++.h>
using namespace std;

const int me=10005;
int t,n;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		long long sum=0,candies;
		for(int i=1;i<=n;i++)cin>>candies,sum+=candies%n;
		if(sum%n)puts("NO");
		else puts("YES");
	}
	return 0;
}
