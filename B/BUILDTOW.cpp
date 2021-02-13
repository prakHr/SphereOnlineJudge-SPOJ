//geeksforgeeks.org/sum-of-squares-of-fibonacci-numbers/

//f(n)*f(n)+f(n-1)*f(n-1)+f(n-2)*f(n-2)+f(n-3)*f(n-3)+..f(1)*f(1)+f(0)*f(0)-f(0)*f(0)
//or f(n)*f(n+1)-1

// f(i) = f(i+1) - f(i-1) for all i>0
//Or, f(i)*f(i) = f(i)*f(i+1) - f(i-1)*f(i)
#include<bits/stdc++.h>
using namespace std;

const int me=3025;

int t;
long long n;
int  mod=1000000007;

map<long long,int> F;
int fib(long long N){
	//using modular exponentiation
	if(F.count(N))return F[N];
	long long k=N/2;
	if(N%2==0)return F[N]=(1LL*fib(k)*fib(k)%mod+1LL*fib(k-1)*fib(k-1)%mod)%mod;
	else return F[N]=(1LL*fib(k)*fib(k+1)%mod+1LL*fib(k-1)*fib(k)%mod)%mod;
}
int main(){
	F[0]=F[1]=1;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<'$'<<(1LL*fib(n)*fib(n+1)%mod-1+mod)%mod<<endl;
	}
	return 0;
}

