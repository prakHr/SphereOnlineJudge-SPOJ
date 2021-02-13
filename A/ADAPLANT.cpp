#include<bits/stdc++.h>
int T;
const int me=300025;
int a[me];
using namespace std;
int main(){
	cin>>T;
	while(T--)
	{
		int N,K;
		cin>>N>>K;
		multiset<int> s;
		int ans=0;
		K+=2;
		for(int i=0;i<N;i++){
			cin>>a[i];
			s.insert(a[i]);
			if(i>=K)
				s.erase(s.find(a[i-K]));
			ans=max(ans,*(s.rbegin())-*(s.begin()));
		}
		cout<<ans;
	}
	return 0;
}
