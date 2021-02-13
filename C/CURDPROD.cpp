#include<bits/stdc++.h>
using namespace std;

const int me=10005;
int t,n,m;
int quality[me];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>quality[i];
			
		long long low=0,high=1LL<<62,best=high;
		while(low<=high){
			long long mid=(low+high+1)/2;
			long long target=0;
			for(int i=1;i<=n && target<m;i++){
				target+=mid/quality[i];
			}
			if(target>=m){
				best=mid;
				high=mid-1;
				
			}
			else{
				low=mid+1;
			}
		}
		cout<<best<<endl;
	}
}
