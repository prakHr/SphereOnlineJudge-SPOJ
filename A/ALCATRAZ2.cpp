#include<bits/stdc++.h>
using namespace std;
const int me=1025;
int M,a,b;
int answer;
int x[10],go[10][10];
int main(){
	for(int i=0;i<8;i++)cin>>x[i];
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>a>>b;
		--a,--b;
		go[a][b]=go[b][a]=1;
	}
	for(int i=1;i<(1<<8);i++){
		int good=1;
		for(int j=0;j<8;j++){
			if(i&(1<<j)){
				for(int k=0;k<8;k++){
					if(i&(1<<k)){
						if(go[j][k])good=0;
					}
				}
			}
		}
		
		if(good){
			int s=0;
			for(int j=0;j<8;j++){
				if(i&(1<<j))s+=x[j];
			}
			answer=max(answer,s);
		}
	
	}
	cout<<answer<<endl;
	return 0;
}
