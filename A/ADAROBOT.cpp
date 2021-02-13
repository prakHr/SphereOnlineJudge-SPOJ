#include<bits/stdc++.h>
using namespace std;

const int me=200000025;
int Q,N;
int cubes[100];
long long t[me];

int main(){
	for(int i=1;i<100;i++){
		cubes[i]=i*i*i;
	}
	for(int i=2;i<me;i++){
		//least significant bit of a=ffsls
		t[i]=t[i-2]+cubes[__builtin_ffsl(1LL*i*(i-1))];
		
	}
	cin>>Q;
	while(Q--){
		cin>>N;
		cout<<t[N]<<endl;
	}
	return 0;
}
