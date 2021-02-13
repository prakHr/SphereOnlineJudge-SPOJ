#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		string u=s;
		reverse(u.begin(),u.end());
		(u==s)?cout<<"YES"<<endl:cout<<"NO"<<endl;;
	}
}
