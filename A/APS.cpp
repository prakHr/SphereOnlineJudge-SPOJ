#include<bits/stdc++.h>
using namespace std;
const int me=10000025;
int n,t;
long long f[me];
int main(){
	for(int i=2;i<me;i++){
		if(!f[i]){
			for(int j=i;j<me;j+=i){
				if(!f[j])f[j]=i;
			}
		}
	}
	for(int i=1;i<me;i++)f[i]+=f[i-1];
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<f[n]<<endl;
	}
	return 0;
}
