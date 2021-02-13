#include<bits/stdc++.h>
using namespace std;

const int me=1<<10;

int t,n;
int order[me];
int visited[me],children[me];

int main(){
	cin>>t;
	for(int c=0;c<t;c++){
		cin>>n;
		for(int i=1;i<=n+n;i++){
			cin>>order[i];
		}
		for(int i=1;i<=n;i++){
			children[i]=visited[i]=0;
		}
		stack<int> stk;
		for(int i=1;i<=n+n;i++){
			if(!visited[order[i]]){
				if(!stk.empty()){
					children[stk.top()]++;
				}
				visited[order[i]]=1;
				stk.push(order[i]);
			}
			else{
				stk.pop();
			}
		}
		cout<<"Case "<<c+1<<":"<<endl;
		for(int i=1;i<=n;i++){
			cout<<i<<" -> "<<children[i]<<endl;
		}
		if(c<t-1)cout<<endl;
	}
	return 0;
}

