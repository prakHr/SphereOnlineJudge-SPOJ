#include<bits/stdc++.h>
using namespace std;

const int MAX = 20005;
int N,Q;
bitset<MAX> bs[MAX];

int main(){
	cin>>Q;
	while(Q--){
		char ch;
		int x,y;
		cin>>ch>>x>>y;
		if(ch=='+')bs[x][y]=1;
		else if(ch=='-')bs[x][y]=0;
		else if(ch=='V')cout<<int((bs[x] | bs[y]).count());
		else if(ch=='^')cout<<int((bs[x] & bs[y]).count());
		else if(ch=='!')cout<<int((bs[x] | bs[y]).count())-int((bs[x] & bs[y]).count());
		else cout<<int((bs[x]^(bs[x] & bs[y])).count());
	}
	return 0;
}
