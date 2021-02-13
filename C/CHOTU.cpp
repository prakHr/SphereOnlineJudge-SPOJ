//https://www.quora.com/What-is-the-logic-behind-the-solution-of-the-SPOJ-question-CHOTU
#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,y,t;
	cin>>t;
	while(t--){
		cin>>x>>y;
		double ans=2*sqrt(x*x-y*y);
		//printf("%.3f\n",ans);
		cout.precision(3);
		cout<<fixed<<ans<<endl;
	
	}
	return 0;
}
