#include<bits/stdc++.h>
using namespace std;

const int S=pow(2,21);

int t,n,m;
vector<int> visited;
void dfs(int node,vector<vector<int > > &graph,int &size){
	visited[node]=1;
	++size;
	for(int n=0;n<graph[node].size();n++){
		if(!visited[graph[node][n]]){
			dfs(graph[node][n],graph,size);
		}
	}
}
int main(){
	vector<int> primes(S,1);
	vector<int> primelist;
	primes[1]=0;
	for(int i=2;i<S;i++){
		if(!primes[i]){
			continue;
		}
		primelist.push_back(i);
		for(int j=2*i;j<S;j+=i){
			primes[j]=0;
		}
	}
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<vector<int > > graph(n+1);
		visited.assign(n+1,0);
		for(int i=0;i<m;i++){
			int u,v;
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int best=-1;
		for(int i=1;i<=n;i++){
			if(visited[i]){
				continue;
			}
			int size=0;
			dfs(i,graph,size);
			if(size>best){
				best=size;
			}
		}
		if(m==0)cout<<-1<<endl;
		else cout<<primelist[best-1]<<endl;
	}
}
