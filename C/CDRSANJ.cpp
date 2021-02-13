#include<bits/stdc++.h>
using namespace std;

const int me=100005;
int n;
int F[me];
vector<int> divisors[me];
int pow30=pow(2,30);
int main(){
	for(int i=0;i<3;i++)F[i]=i;
	
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			divisors[j].push_back(i);
	
	for(int i=3;i<=n;i++){
		if((int)divisors[i].size()==2)F[i]=0;
		else{
			F[i]=pow30;
			int best=pow30,bestSum=pow30;
			for(int j=0;j<divisors[i].size();j++){
				if(divisors[i][j]+i/divisors[i][j]<bestSum){
					best=divisors[i][j];
					bestSum=divisors[i][j]+i/divisors[i][j];
				}
			}
			F[i]=F[best]+F[i/best];
		}
	}
	cout<<F[n]<<endl;
	return 0;
}
