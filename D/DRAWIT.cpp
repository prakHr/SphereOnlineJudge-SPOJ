#include<bits/stdc++.h>
using namespace std;

const int me=125;

int t,n,m;
int visited[me],degree[me];
vector<int > edges[me];

void dfs(int node){
	visited[node]=1;
	for(int i=0;i<edges[node].size();i++){
		if(visited[edges[node][i]])
			continue;
		dfs(edges[node][i]);
	}
}
int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m;
		
		for(int i=1;i<=n;i++)
		{
			edges[i].clear();
			degree[i]=0;
		}
		for(int i=0;i<m;i++){
			
			int u,v,c;
			cin>>u>>v>>c;
			
			edges[u].push_back(v);
			edges[v].push_back(u);
			
			degree[u]+=c;
			degree[v]+=c;
		}
		dfs(1);
		int flag=1;
		for(int i=1;i<=n;i++){
			if(!visited[i])
			{
				flag=0;
				break;
			}
			
		}
		if(!flag){
			 cout<<"NO"<<endl;
			 continue;
		}
		int odd=0;
		for(int i=1;i<=n;i++){
			if(degree[i]%2)
				odd++;
		}
		if(odd>2)cout<<"NO"<<endl;
		else if(odd==0)cout<<"YES "<<1<<endl;
		else{
			int result=-1;
			for(int i=1;i<=n;i++){
				if(degree[i]%2){
					result=i;
					break;
				}
			}
			cout<<"YES"<<result<<endl;
		}
	}
	return 0;
}
