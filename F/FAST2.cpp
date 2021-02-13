#include<bits/stdc++.h>
using namespace std;

const long long unsigned mod=1298074214633706835075030044377087;
int t;
long long unsigned f[505];
int main(){
	f[0]=2;
	for(int i=1;i<505;i++){
		f[i]=f[i-1]*2%mod;
	}
	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<f[n]-1<<endl;
	}
	return 0;
}

