#include<bits/stdc++.h>
using namespace std;

const int me = 325;

int n,m;
int a[me][me], ft[me][me];
vector<pair<int, pair<int, int > > > data;

void add(int x,int y){
	for(int i=x;i<me;i+=(i&-i)){
		for(int j=y;j<me;j+=(j&-j))
		{
			ft[i][j]++;
		}
	}
}
int get(int x,int y){
	int s=0;
	for(int i=x;i>0;i-=(i&-i)){
		for(int j=y;j>0;j-=(j&-j)){
			s+=ft[i][j];
		}
	}
	return s;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			data.push_back(make_pair(a[i][j],make_pair(i,j)));
		}
	}
	sort(data.begin(),data.end());
	int res=0,added=0;
	for(int i=0;i<data.size();i++){
		int x=data[i].second.first,y=data[i].second.second;
		res+=added-get(x-1,me-1)-get(me-1,y-1)+get(x-1,y-1);
		add(x,y);
		added++;
	}
	cout<<res<<endl;
}
