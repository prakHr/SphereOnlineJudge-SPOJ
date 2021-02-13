//https://github.com/tr0j4n034/SPOJ/blob/master/BRCKTS.cpp
//https://www.spoj.com/problems/BOMARBLE/
#include<bits/stdc++.h>
using namespace std;

const int me=100005;

int main(){
	int n;
	while(1){
		cin>>n;
		if(n==0)break;
		++n;
		int triangular_num=n*(3*n-1)/2;
		cout<<triangular_num<<endl;
	}
	return 0;
}

