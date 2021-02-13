#include<bits/stdc++.h>
using namespace std;

const int me=1000025;
const int mod= 1000000007;

int N,A,B,D;
int fac[me],inv[me];

int bin_pow(int a,int b){
	if(b==0)return 1;
	if(b&1)return 1LL * bin_pow(a,b-1) * a % mod;
	int half=bin_pow(a,b/2);
	return 1LL * half * half % mod;
}
int comb(int n,int k){
	return 1LL * fac[n] * inv[k] % mod *inv[n-k] % mod;
}
int main(){
	fac[0]=inv[0]=1;
	for(int i=1;i<me;i++){
		fac[i] = 1LL * fac[i-1] * i % mod;
		inv[i] = bin_pow(fac[i],mod-2);
		
	}
	while(scanf("%d%d%d%d",&N,&A,&B,&D)!=EOF){
		int result = 1LL * comb(N,A) * bin_pow(comb(B,D),A) % mod;
		cout<<result<<endl;
	}
	return 0;
}
