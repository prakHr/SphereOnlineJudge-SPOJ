#include<bits/stdc++.h>
using namespace std;

const int me=100025,size=50;
int n,c=0;
int dp[me];
int main(){
	for(int i=1;i<me;i++){
		dp[i]=i;
		for(int j=1;j*j*j<=i;j++){
			dp[i]=min(dp[i],dp[i-j*j*j]+1);
		}
	}
		while(scanf("%d",&n)!=EOF){
			cout<<"Case #"<<++c<<": "<<dp[n]<<endl;
		}
	
}

