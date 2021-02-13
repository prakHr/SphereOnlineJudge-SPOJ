#include<bits/stdc++.h>

using namespace std;
const int me=300025;
int N;
int a[me];
map<int,int> lengths;
int main(){
	cin>>N;
	for(int i=1;i<=N;i++)scanf("%d", &a[i]);
	long long result=0;
	for(int i=1;i<=N;i++){
		map<int,int> new_lengths;
		std::map<int,int>::iterator it = lengths.begin();
		while(it!=lengths.end()){
			int to = __gcd(a[i],it->first);
			new_lengths[to]+=(it->second);
			it++;
		}
		new_lengths[a[i]]++;
		lengths=new_lengths;
		std::map<int,int>::iterator it1 = lengths.begin();
		while(it1!=lengths.end()){
			result+=1LL*(it1->first)*(it1->second);
			it1++;
		}
		
	}
	cout<<result<<endl;
	return 0;
}
