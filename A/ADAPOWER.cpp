#include<bits/stdc++.h>
using namespace std;

int N,Q;
const int me=225;
int a[me][me],b[me][me],c[me][me];

int main(){
	cin>>N>>Q;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%d",&a[i][j]);
		}
	}
	while(Q--){
		int type;
		cin>>type;
		if(type==1){
			int x,y,X,Y,value;
			cin>>x>>y>>X>>Y>>value;
			for(int i=x+1;i<=X+1;i++){
				for(int j=y+1;j<=Y+1;j++){
					a[i][j]+=value;
				}
			}
		}
		else{
			for(int i=1;i<=N;i++){
				for(int j=1;j<=N;j++){
					scanf("%d",&b[i][j]);
				}
			}
			bool same=true;
			for(int i=1;i<=N;i++){
				for(int j=1;j<=N;j++){
					c[i][j]=0;
				}
			}
			for(int i=1;i<=N && same;i++){
				for(int j=1;j<=N && same;j++){
					for(int k=1;k<=N && same;k++){
						c[i][j]+=a[i][k]*a[k][j];
						if(c[i][j]>b[i][j]){
							same=false;
							break;
						}
					}
				}
			}
			for(int i=1;i<=N;i++){
				for(int j=1;j<=N;j++){
					if(b[i][j]!=c[i][j]){
						same=false;
						break;
					}
				}
			}
			if(same)puts("yes");
			else puts("no");
		}
	}
	return 0;
}
