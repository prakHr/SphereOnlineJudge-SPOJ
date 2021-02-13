#include<bits/stdc++.h>

using namespace std;
const int maxx=100005;

int powmod(int a,int b,int mod){
	int res=1;
	a%=mod;
	while(b>0){
		if(b&1)res=(1LL*res*a)%mod;
		a=(1LL*a*a)%mod;
		b=b>>1;
	}
	return res;
}
const int MOD=1e9+7;
int fac[maxx*2];
int main(){
	fac[0]=1;
	for(int i=1;i<2*maxx;i++)fac[i]=1LL*fac[i-1]*i % MOD;
	int n;
	while(cin>>n){
		int res=0;
		for(int i=1;i<=n-1;i++)
		{
			res = (res + (1LL * powmod(i, n - i - 1, MOD) * powmod(n - i, i - 1, MOD) % MOD)) % MOD;
		}
		res=(1LL*res*fac[n])%MOD;
		cout<<res<<endl;
	}
	return 0;
}
