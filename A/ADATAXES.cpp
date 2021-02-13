#include<bits/stdc++.h>
using namespace std;

const int me=300025;
const int mod= 1000000007;

int N,Q;
int a[me];
vector<int> st[4*me],products[4*me];
void merge(vector<int> &a,vector<int> &b,vector<int> &c){
	int l1=(int)a.size();
	int l2=(int)b.size();
	int ptr1=0,ptr2=0;
	while(ptr1<l1 && ptr2<l2){
		if(a[ptr1]<b[ptr2])c.push_back(a[ptr1++]);
		else c.push_back(b[ptr2++]);
	}
	while(ptr1<l1)c.push_back(a[ptr1++]);
	while(ptr2<l2)c.push_back(b[ptr2++]);
	
}
void build_products(int id){
	int now=st[id][0];
	products[id].push_back(now);
	for(int i=1;i<(int)st[id].size();i++){
		now=1LL*now*st[id][i]%mod;
		products[id].push_back(now);
	}
}
void build(int I,int low,int high){
	if(low==high){
		st[I].push_back(a[low]);
		products[I].push_back(a[low]);
		return;
	}
	int mid=(low+high)>>1;
	build(2*I,low,mid);
	build(2*I+1,mid+1,high);
	merge(st[2*I],st[2*I+1],st[I]);
	build_products(I);
}
int get(int id,int h){
	if(st[id][0]>h)return 1;
	int pos=(int)(--upper_bound(st[id].begin(),st[id].end(),h)-st[id].begin());
	return products[id][pos];
}
int get(int I,int low,int high,int l,int r,int h){
	if(low>r || high<l)return 1;
	if(low>=l && high<=r)return get(I,h);
	int mid=(low+high)/2;
	return 1LL*get(2*I,low,mid,l,r,h)*get(2*I+1,mid+1,high,l,r,h)%mod;
}
int main(){
	cin>>N>>Q;
	for(int i=1;i<=N;i++)cin>>a[i];
	build(1,1,N);
	while(Q--){
		int l,r,h;
		cin>>l>>r>>h;
		cout<<get(1,1,N,l+1,r+1,h)<<endl;
	}
	return 0;
}
