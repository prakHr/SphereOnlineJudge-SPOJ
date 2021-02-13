#include<bits/stdc++.h>
using namespace std;

const int me=5025;
int t,n,k;
int arr[150],dp[me];

int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n;i++)cin>>arr[i];
		
		fill(dp+1,dp+me,12345);
		
		for(int i=0;i<n;i++)
			for(int j=k-arr[i];j>=0;j--)
				dp[j+arr[i]]=min(dp[j+arr[i]],dp[j]+1);
		
		if(dp[k]==12345)
			cout<<"impossible"<<endl;
		else cout<<dp[k]<<endl;
	}
}
