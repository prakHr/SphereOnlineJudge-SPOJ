#include<bits/stdc++.h>
using namespace std;
const int me = 1000025;
int primes[me],lp[me],phi[me];

int main(){
	for(int i=2;i<me;i++){
		if(!primes[i]){
			for(int j=i;j<me;j+=i){
				primes[j]=1;
				lp[j]=i;
			}
		}
	}
	phi[1]=1;
	for(int i=2;i<me;i++){
		int j=i;
		while(j%lp[i]==0){
			j=j/lp[i];
		}
		phi[i]=phi[j]*(lp[i]-1)*i/j/lp[i];
	}
	long long int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<phi[n]<<endl;
	}
	
	return 0;
	
	
}
