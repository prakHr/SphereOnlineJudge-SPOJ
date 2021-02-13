#include<bits/stdc++.h>
using namespace std;

const int me = 10025;

int n, k, s;
int a[me];

int main(){
	cin>>n>>k>>s;
	s=s*k;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int l=0;
	for(int j=n-1;j>=0;j--){
		s=s-a[j];
		l++;
		if(s<l)break;
	}
	cout<<l<<endl;

	return 0;
}
