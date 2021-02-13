#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,D;
	while(cin>>N>>D){
		if(N+D==0)break;
		int position=1;
		for(int i=1;i<=N;i++)position=(position + D) % i;
		cout<<N<<" "<<D<<" "<<position+1;
	}
	return 0;
}
