#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1<<10;
const int MAX_LEVELS = 10;

int N,Q;
vector<vector<int> > graph;

int depth[MAX_SIZE];
int parents[MAX_SIZE][MAX_LEVELS];

void dfs(int node,int parent){
	//node at starting level 0 assigned as parents[node][lvl]
	parents[node][0]=parent;
	for(int i=0;i<graph[node].size();i++){
		if(graph[node][i]!=parent){
			depth[graph[node][i]]=depth[node]+1;
			dfs(graph[node][i],node);
		}
	}
}

int lca(int u,int v){
	if(depth[u]<depth[v]){
		swap(u,v);
	}
	for(int i=MAX_LEVELS - 1;i>=0;i--){
		if(depth[u]>=depth[v]+pow(2,i)){
			u=parents[u][i];
		}
	}
	if(u==v){
		return u;
	}
	for(int i=MAX_LEVELS - 1;i>=0;i--){
		if(parents[u][i]!=0 && parents[u][i]!=parents[v][i]){
			u=parents[u][i];
			v=parents[v][i];
		}
		
	}
	return parents[u][0];
}
int main(){
	cin>>N;
	graph.resize(N+1);
	for(int i=1;i<N;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<MAX_LEVELS;i++){
		for(int j=1;j<=N;j++){
			if(parents[j][i-1]!=0){
				parents[j][i]=parents[parents[j][i-1]][i-1];
			}
		}
	}
	cin>>Q;
	for(int c=0;c<Q;c++){
		int u,v;
		cin>>u>>v;
		cout<<"Case "<<c+1<<": ";
		if(u!=v && lca(u,v)==v){
			cout<<"WOW"<<endl;
		}
		else{
			cout<<"NO WAY"<<endl;
		}
	}
	return 0;
}
