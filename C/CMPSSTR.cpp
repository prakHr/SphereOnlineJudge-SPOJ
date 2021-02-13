#include<bits/stdc++.h>
using namespace std;

const int me=125;
int N,M;
string a,b;
int dp[me][me];

int main(){
	while(getline(cin,a)){
		
		getline(cin,b);
		
		N=(int)a.size();
		M=(int)b.size();
		
		a="$"+a;
		b="$"+b;
		int result=0;
		
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++)
				dp[i][j]=0;
		
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=M;j++)
			{
				if(a[i]==b[j]){
					dp[i][j]=dp[i-1][j-1]+1;
					result=max(result,dp[i][j]);
				}
				else{
					dp[i][j]=0;
				}			
			}
		}	
		cout<<result<<endl;
	}
	return 0;
}
