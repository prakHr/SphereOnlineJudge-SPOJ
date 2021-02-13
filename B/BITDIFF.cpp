#include<bits/stdc++.h>
using namespace std;

const int me=100025;

int t,x,n;
int cnt[32];
int main(){
	cin>>t;
	for(int c=0;c<t;c++){
		cin>>n;
		
		for(int i=0;i<32;i++)
			cnt[i]=0;
			
		for(int i=0;i<n;i++){
			cin>>x;
			for(int j=0;j<32;j++)
				if(x&(1<<j))
					cnt[j]++;
				
		}
		int ans =0;
		for(int i=0;i<32;i++)
			ans = (ans + 1LL * cnt[i] * (n - cnt[i]) % 10000007) % 10000007;
        ans = (2LL * ans) % 10000007;
        cout << "Case " << c + 1 << ": " << ans << endl;
		
	}
	return 0;
}
