#include<bits/stdc++.h>
using namespace std;

const long long int mod=109546051211;
int n;
int main(){
	cin>>n;
	long long int p=1,fac=1;
	for(int i=1;i<=n;i++){
		fac=fac*i%mod;
		p=p*fac%mod;
		if(p==0)break;
	}
	cout<<p;
	return 0;
}

