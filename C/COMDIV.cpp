//The number of common divisors of two numbers is simply the number of divisors of their gcd.
#include<bits/stdc++.h>
using namespace std;

const int me=1000025;
int t,n,m;
int dp[me];
int main(){
	for(int i=1;i<me;i++)
		for(int j=i;j<me;j+=i)
			dp[j]++;
	cin>>t;
	while(t--)
		cin>>n>>m,cout<<dp[__gcd(n,m)]<<endl;
		
}

