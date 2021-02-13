#include<bits/stdc++.h>
using namespace std;

const int MAX=300005;
int N,Q;
int data[MAX];
vector<int> stree[4*MAX];

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
void buildTree(int I,int low,int high){
	if(low==high){
		stree[I]=vector<int>(1,data[low]);
		return;
	}
	int mid=(low+high)/2;
	buildTree(2*I,low,mid);
	buildTree(2*I+1,mid+1,high);
	merge(stree[2*I],stree[2*I+1],stree[I]);
	
}
int get(int I,int low,int high,int l,int r,int height){
	if(low>r || high<l)return 0;
	if(low>=l && high<=r){
		vector<int>::iterator it=--lower_bound(stree[I].begin(),stree[I].end(),height+1);
		if(*it>height)return 0;
		return *it;
	}
	int mid=(low+high)/2;
	return max(get(2*I,low,mid,l,r,height),
	get(2*I+1,mid+1,high,l,r,height));
}
int main(){
	cin>>N>>Q;
	for(int i=1;i<=N;i++)cin>>data[i];
	buildTree(1,1,N);
	while(Q--){
		int l,r,height;
		cin>>l>>r>>height;
		
		l++;r++;
		
		cout<<get(1,1,N,l,r,height)<<endl;
	}
	return 0;
}
