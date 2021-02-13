//https://github.com/tr0j4n034/SPOJ/blob/master/BLUNIQ.cpp
#include<bits/stdc++.h>
using namespace std;

const int me=51;
#define f(i, a, b) for(int i = a; i <= b; i ++)

int n;
int cubes[me];

int main(){
	f(i,1,me-1)
		cubes[i]=i*i*i;
		
	cin>>n;
	int ans=0;
	f(i,1,me-1){
		if(cubes[i]>n)
			break;
		if(cubes[i]==n)
			ans++;
		
		f(j,i,me-1){
			if(cubes[i]+cubes[j]>n)
				break;
			if(cubes[i]+cubes[j]==n)
				ans++;
			
			f(k,j,me-1){
				if(cubes[i]+cubes[j]+cubes[k]>n)
					break;
				if(cubes[i]+cubes[j]+cubes[k]==n)
					ans++;
				
				f(q,k,me-1){
					if(cubes[i]+cubes[j]+cubes[k]+cubes[q]>n)
						break;
					if(cubes[i]+cubes[j]+cubes[k]+cubes[q]==n)
						ans++;
					
					f(l,q,me-1){
						if(cubes[i]+cubes[j]+cubes[k]+cubes[q]+cubes[l]>n)
							break;
						if(cubes[i]+cubes[j]+cubes[k]+cubes[q]+cubes[l]==n)
							ans++;
							break;	
					}
				}
			}
		
		}
	}
	 cout << ans << endl;
    
	return 0;
}
