#include<bits/stdc++.h>
using namespace std;
 
const int S = 1<<17;
int T,N,M;
vector<int> visited;

void dfs(int node,vector<vector<int> > &graph,int &size){
	visited[node]=1;
	++size;
	for(int i=0;i<graph[node].size();i++){
		int neighbor=graph[node][i];
		if(!visited[neighbor])dfs(neighbor,graph,size);
	}
}
int main(){
	vector<int> primes(S,1);
	primes[1]=0;
	for(int i=2;i<S;i++){
		if(!primes[i])continue;
		for(int j=i+1;j<S;j+=i)primes[j]=0;
	}
	cin>>T;
	while(T--){
		cin>>N>>M;
		vector<vector<int> > graph(N+1);
		visited.assign(N+1,0);
		for(int i=0;i<M;i++){
			int u,v;
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int best=-1;
		for(int i=1;i<=N;i++){
			if(visited[i])continue;
			int size=0;
			dfs(i,graph,size);
			if(primes[size] && size>best)
			{
				best=size;
			}
		}
		cout<<best<<endl;
	}
	return 0;
}
