//https://github.com/tr0j4n034/SPOJ/blob/master/CAPCITY.cpp
#include<bits/stdc++.h>
using namespace std;

const int MAX=100005;

int N,M;
int componentCount[2];
int componentID[2][MAX];
int degree[MAX];
int visited[2][MAX];

vector<int> orders;
vector<int> Graph[MAX],reverseGraph[MAX];

void dfs1(int node){
	visited[0][node]=true;
	componentID[0][node]=componentCount[0];
	for(int i=0;i<reverseGraph[node].size();i++){
		if(!visited[0][reverseGraph[node][i]]){
			dfs1(reverseGraph[node][i]);
		}
	}
	orders.push_back(node);
}

void dfs2(int node){
	visited[1][node]=true;
	componentID[1][node]=componentCount[1];
	for(int i=0;i<Graph[node].size();i++){
		if(!visited[1][Graph[node][i]]){
			dfs2(Graph[node][i]);
		}
	}
	
}
int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int u,v;
		cin>>u>>v;
		Graph[u].push_back(v);
		reverseGraph[v].push_back(u);
	}
	for(int i=1;i<=N;i++){
		if(!visited[0][i]){
			componentCount[0]++;
			dfs1(i);
		}
	}
	reverse(orders.begin(),orders.end());
	
	for(int i=0;i<orders.size();i++){
		if(!visited[1][orders[i]]){
			componentCount[1]++;
			dfs2(orders[i]);
		}
	}
	
	for(int i=1;i<=N;i++){
		for(int j=0;j<reverseGraph[i].size();j++){
			if(componentID[1][i]!=componentID[1][reverseGraph[i][j]]){
				degree[componentID[1][reverseGraph[i][j]]]++;
			}
		}
	}
	int startings=0;
	for(int i=1;i<=componentCount[1];i++){
		if(!degree[i]){
			startings++;
		}
	}
	if(startings>1){
		puts("0");
	}
	else{
		vector<int> output;
		for(int i=1;i<=N;i++){
			if(!degree[componentID[1][i]]){
				output.push_back(i);
			}
		}
		cout<<(int)output.size()<<endl;
		for(int i=0;i<(int)output.size();i++){
			printf("%d",output[i]);
			if(i<(int)output.size()-1){
				putchar(' ');
			}
		}
		putchar('\n');
	}
	
	return 0;
}
