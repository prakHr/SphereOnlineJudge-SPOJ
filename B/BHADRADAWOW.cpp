#include<bits/stdc++.h>
using namespace std;

const int me=100025;
int T,N;
string s;
int main(){
	cin>>T;
	while(T--){
		cin>>N>>s;
		int w=0,o=0;
		for(int i=0;i<N;i++){
			if(s[i]=='w'||s[i]=='W')w++;
			else if(s[i]=='o'||s[i]=='O')o++;
		}
		cout<<min(w/2,o)<<endl;
	}
	return 0;
}
