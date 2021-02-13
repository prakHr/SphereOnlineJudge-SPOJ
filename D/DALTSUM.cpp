#include<bits/stdc++.h>
using namespace std;

const int me=100025;
const int mod=1000000007;

int n;
long long arr[me];

int main(){
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	long long m=*max_element(arr,arr+n);
	m%=mod;
	if(mod<0)m+=mod;
	for(int i=1;i<n;i++){
		m=m*2%mod;
	}
	cout<<m<<endl;
	return 0;
}
