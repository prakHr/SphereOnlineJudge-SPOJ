#include<bits/stdc++.h>
using namespace std;

const int me=100025;

int T,N;
string s;
int sum[me];

int main(){
	cin>>T;
	while(T--){
		cin>>s;
		N=(int)s.size();
		for(int i=1;i<=N;i++)
			sum[i]=sum[i-1]+(s[i-1]=='K');
			
		int result=0;
		for(int i=1;i<=N;i++)
			if(s[i-1]=='E')
				result+=sum[i-1]*(sum[N]-sum[i]);
		
		cout<<result<<endl;
	}
	return 0;
}
