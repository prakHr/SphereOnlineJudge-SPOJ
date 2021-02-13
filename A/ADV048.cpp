//https://mathworld.wolfram.com/DelannoyNumber.html
#include<bits/stdc++.h>
using namespace std;

const int MAX=1005;
const int mod=1000003;

int T, N;
int g[MAX];

int bin_pow(int a,int b,int mod){
	if(b==0)return 1 % mod;
	if(b&1)return 1LL * bin_pow(a,b-1,mod) * a % mod;
	int half=bin_pow(a,b/2,mod);
	return 1LL * half * half % mod;
}

int inverse(int a,int mod){
	return bin_pow(a,mod-2,mod);
}
int main(){
	g[0]=1;
	g[1]=3;
	for(int i=2;i<MAX;i++)
		g[i]=1LL*(3LL*(2*i-1)*g[i-1] % mod -1LL*(i-1)*g[i-2]%mod+mod)%mod
		*inverse(i,mod)%mod;
	cin>>T;
	while(T--){
		cin>>N;
		cout<<g[N-1]<<endl;
	}
	return 0;
}
