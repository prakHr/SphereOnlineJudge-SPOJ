#include<bits/stdc++.h>
using namespace std;
 
const int me = 7025;
 
int t, n;
char a[me], b[me];
int dp[me][me];
 
 
int main(){
	cin>>t;
	while(t--){
		scanf(" %s",a);
		n=(int)strlen(a);
		for(int i=0;i<n;i++)b[i]=a[n-1-i];
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i]==b[j])dp[i][j]=(i>0 && j>0)?dp[i-1][j-1]+1:1;
				else dp[i][j]=max((i>0)?dp[i-1][j]:0,(j>0)?dp[i][j-1]:0);
			}
		}
		cout<<n-dp[n-1][n-1]<<endl;
	}
	return 0;
}
