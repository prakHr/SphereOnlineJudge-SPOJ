#include<bits/stdc++.h>
using namespace std;

const int me = 1000025;
const int fixx=10;

int t,n,x;
long long ft[me];

void add(int pos,int value){
	pos+=fixx;
	for(;pos<me;pos+=(pos&-pos)){
		ft[pos]+=value;
	}
}
long long get(int pos){
	pos+=fixx;
	long long s=0;
	for(;pos>0;pos-=(pos&-pos))
		s+=ft[pos];
	return s;
}

int main(){
	cin>>t;
	while(t--){
		fill(ft,ft+me,0);
		long long s=0;
		cin>>n;
		while(n--){
			cin>>x;
			s+=get(x-1);
			add(x,x);
		}
		cout<<s<<endl;
	}
}
