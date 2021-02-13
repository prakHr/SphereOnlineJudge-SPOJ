#include<bits/stdc++.h>
using namespace std;


const int me=1025;
int T,N,M;
int cnt;
char ch;
char ar[me][me],visited[me][me];

int isValid(int x,int y){
	return x>0 && y>0 && x<=N && y<=M;
}

void dfs(int x,int y){
	visited[x][y]=1;
	cnt++;
	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++)
		{
			if(i*i+j*j==1)
			{
				if(isValid(x+i,y+j) && !visited[x+i][y+j] && ar[x+i][y+j]=='#')
					dfs(x+i,y+j);
					
			}
		}
	}
}
long long gcd(long long a,long long b){
	while(a>0 && b>0){
		if(a>b)a%=b;
		else b%=a;
	}
	return a+b;
}
int main(){
	cin>>T;
	while(T--){
		cin>>N>>M;
		getchar();
		for(int i=1;i<=N;i++){
			int j=1;
			while((ch=getchar())!='\n')
				ar[i][j++]=ch;
		}
		long long p=0;
		long long q=N*M;
		
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++)
				visited[i][j]=0;
		
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++)
				if(!visited[i][j] && ar[i][j]=='#'){
					cnt=0;
					dfs(i,j);
					p+=1LL*cnt*cnt;
				}
		long long g=gcd(p,q);
		p/=g,q/=g;
		if(q==1)cout<<p<<endl;
		else cout<<p<<" / "<<q<<endl;
	}
	return 0;
}

