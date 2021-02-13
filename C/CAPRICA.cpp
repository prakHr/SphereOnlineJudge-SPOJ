//https://github.com/tr0j4n034/SPOJ/blob/master/CAPRICA.cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,a,b;
	while(1){
		cin>>n>>m>>a>>b;
		
		if(n+m+a+b==0)break;
		
		vector<int> citiesA,citiesB;
		vector<int> distances(n+1,pow(2,30));
		vector<vector<pair<int,int > > > edges(n+1);
		
		for(int i=0;i<a;i++){
			int id;
			cin>>id;
			citiesA.push_back(id);
			edges[0].push_back(make_pair(id,0));
			edges[id].push_back(make_pair(0,0));
		}
		for(int i=0;i<b;i++){
			int id;
			cin>>id;
			citiesB.push_back(id);
			edges[n].push_back(make_pair(id,0));
			edges[id].push_back(make_pair(n,0));
		}
		for(int i=0;i<m;i++){
			int from,to,length;
			cin>>from>>to>>length;
			edges[from].push_back(make_pair(to,length));
			edges[to].push_back(make_pair(from,length));
		}
		//Dijkstra
		priority_queue<pair<int,int > > Q;
		
		Q.push(make_pair(0,0));
		
		while(!Q.empty()){
			pair<int,int> current=Q.top();
			Q.pop();
			int id=current.second;
			int d=current.first;
			
			if(d > distances[id])continue;
			
			for(int i=0;i<edges[id].size();i++){
				int u=edges[id][i].first;
				int vLen=edges[id][i].second;
				if(distances[u]>d+vLen){
					distances[u]=d+vLen;
					Q.push(make_pair(distances[u],u));
				}
			}
		}
		cout<<distances[n]<<endl;
	}
	return 0;
}

