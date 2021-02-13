#include<bits/stdc++.h>
using namespace std;
const int S=100005;

int T,N;
pair<int,int> data[S];
int main(){
	cin>>T;
	for (int _ = 0; _ < T; _ ++){
		cin>>N;
		for(int i=1;i<=N;i++){
			cin>>data[i].first;
			data[i].second=i;
		}
		sort(data+1,data+N+1);
		int result=-1;
		if(N&1)result=data[N/2+1].second;
		else result=min(data[N/2].second,data[N/2+1].second);
		printf("Case %d: %d\n", _ + 1, result);
	}
}
