#include<bits/stdc++.h>
using namespace std;

const int MAX=1105;

int N,M;
bool visited[MAX];
int color[MAX];
vector<int> edges[MAX];

bool dfs(int node,int c){
	visited[node]=1;
	color[node]=c;
	bool result=true;
	for(int i=0;i<edges[node].size();i++){
		if(color[edges[node][i]]==c){
			result=false;
			break;
		}
		if(!visited[edges[node][i]]){
			result=result & dfs(edges[node][i],1-c);
		}
	}
	return result;
} 
int main(){
	while(cin>>N){
		if(N==0)break;
		cin>>M;
		for(int i=0;i<N;i++){
			edges[i].clear();
			visited[i]=0;
			color[i]=-1;
		}
		for(int i=0;i<M;i++){
			int u,v;
			cin>>u>>v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		bool result=true;
		for(int i=0;i<N && result;i++){
			if(!visited[i]){
				result=result & dfs(i,0);
			}
		}
		if(result==true){
			puts("BICOLORABLE");
		}
		else puts("NOT BICOLORABLE");
	}
}
