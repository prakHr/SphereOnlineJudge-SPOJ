#include<bits/stdc++.h>
using namespace std;

const int me=1025;
int n;
int dp[me][2];
string s;
int main(){
	while(cin>>s){
		s="$"+s;
		n=(int)s.size();
		for(int i=1;i<n;i++){
			if(isupper(s[i])){
				dp[i][0]=dp[i-1][1]+1;
				dp[i][1]=dp[i-1][0];
			}
			else{
				dp[i][1]=dp[i-1][0]+1;
				dp[i][0]=dp[i-1][1];
			}
		}
		cout<<min(dp[n-1][0],dp[n-1][1])<<endl;
	}
}
