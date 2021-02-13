#include<bits/stdc++.h>
using namespace std;
const int me=1000025;
int T,N;
int lowest_prime[me];

int main(){
	for(int i=2;i<me;i++){
		if(!lowest_prime[i]){
			for(int j=i;j<me;j+=i){
				lowest_prime[j]=i;
			}
		}
	}
	cin>>T;
	while(T--){
		cin>>N;
		int result=0;
		while(N>1){
			int d=lowest_prime[N];
			int count=0;
			while(N%d==0){
				count++;
				N=N/d;
			}
			result=max(result,count);
		}
		cout<<result<<endl;
	}
	return 0;
}
