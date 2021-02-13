#include<bits/stdc++.h>
using namespace std;

const int me = 1000025;

int N,M,L;
int x,y;
int ar[me];

int main(){
	cin>>N>>M>>L;
	for(int i=0;i<N;i++){
		cin>>x>>y;
		ar[x]++;
		ar[y+1]--;
	}
	for(int i=1;i<=L;i++){
		ar[i]+=ar[i-1];
	}
	while(M--){
		cin>>x;
		cout<<ar[x];
	}

	return 0;
}
