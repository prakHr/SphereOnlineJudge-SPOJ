
//https://github.com/tr0j4n034/SPOJ/blob/master/CHOTU.py
//https://github.com/tr0j4n034/SPOJ/blob/master/CHARGY.cpp
//https://github.com/tr0j4n034/SPOJ/blob/master/CMPSSTR.cpp
//https://github.com/tr0j4n034/SPOJ/blob/master/CODECODE.cpp
//https://github.com/tr0j4n034/SPOJ/blob/master/CODEM5.cpp
//https://github.com/tr0j4n034/SPOJ/blob/master/COMDIV.cpp
//https://github.com/tr0j4n034/SPOJ/blob/master/CTTC.cpp
//https://github.com/tr0j4n034/SPOJ/blob/master/CUBNUM.cpp(dp)
//https://github.com/tr0j4n034/SPOJ/blob/master/CURDPROD.cpp(binary search)
//https://github.com/tr0j4n034/SPOJ/blob/master/CWC2015.cpp(bitset)

//https://www.spoj.com/problems/CAPRICA

//read more about fenwick trees on codencode

#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;

struct matrix{
	long long a[2][2];
	matrix(){
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				a[i][j]=0;
	}
};
matrix mul(matrix a,matrix b){
	matrix c;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			c.a[i][j]=0;
			
	
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j] % mod) % mod;
						
	return c;
}
matrix power(matrix a,long long b){
	if(b==1)return a;
	if(b&1)return mul(power(a,b-1),a);
	matrix half=power(a,b/2);
	return mul(half,half);
}
int t;
long long n;
int main(){
	matrix f;
	f.a[0][0]=1;
	f.a[0][1]=1;
	f.a[1][0]=1;
	f.a[1][1]=0;
	
	cin>>t;
	for(int c=0;c<t;c++){
		cin>>n;
		matrix fn=power(f,n);
		cout<<"Case "<<c+1<<": "<<1LL*fn.a[0][0]*fn.a[0][1]%mod<<endl;
	}
	return 0;
}
