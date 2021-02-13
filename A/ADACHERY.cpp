#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <bitset>
using namespace std;

const int MAX=100005;
int N,M;

int degree[MAX];
vector<pair<int,int> > edges;
bitset<MAX> bs[MAX];



int main(){
	
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int u,v;
		cin>>u>>v;
		bs[u][v]=bs[v][u]=1;
		degree[u]++;
		degree[v]++;
		edges.push_back(make_pair(u,v));
	}
	long long all=0,bad=0;
	for(int i=0;i<N;i++)all+=1LL*degree[i]*(degree[i]-1)/2;
	for(int i=0;i<edges.size();i++)
	{
		bad+=(bs[edges[i].first] & bs[edges[i].second]).count();
	}
	cout<<all-bad;
	return 0;
}
