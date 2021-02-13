#include<bits/stdc++.h>
using namespace std;
 
const int me = 100025;

int T,N,K;
int dp[me][2];

int main(){
	cin>>T;
	while(T--){
		cin>>N>>K;
		dp[1][0]=dp[1][1]=1;
		for(int i=2;i<=N;i++){
			dp[i][0]=(dp[i-1][0]+dp[i-1][1])%5000011;
			dp[i][1]=i>K+1?(dp[i-K-1][0]+dp[i-K-1][1])%5000011:1;
		}
		cout<<dp[N][0]+dp[N][1]<<endl;
	}
	return 0;
}
