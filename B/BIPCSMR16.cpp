#include<bits/stdc++.h>
using namespace std;

const int me=100025;

int T;
long long v[3];

long long solve(){
	sort(v,v+3);
	if(v[2]>=(v[0]+v[1])*2)
		return v[0]+v[1];
	long long sum=v[0]+v[1]+v[2];
	return sum/3;
}
int main(){
	cin>>T;
	while(T--){
		cin>>v[0]>>v[1]>>v[2];
		cout<<solve()<<endl;
	}
	return 0;
}
