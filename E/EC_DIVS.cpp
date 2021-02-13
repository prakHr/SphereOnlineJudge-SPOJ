#include<bits/stdc++.h>
using namespace std;

const int MAX=10005;

int t,n;
int data,listSize;
int primes[MAX],counts[MAX];
char type[5];

vector<int > divisors[MAX];
set<int > active[MAX];
set<int >::iterator itr;

void add(int data){
	listSize++;
	for(int i=0;i<divisors[data].size();i++){
		counts[divisors[data][i]]++;
		if(counts[divisors[data][i]]>1)
			active[counts[divisors[data][i]]-1].erase(divisors[data][i]);
		active[counts[divisors[data][i]]].insert(divisors[data][i]);
	}
}
void remove(int data){
	listSize--;
	for(int i=0;i<divisors[data].size();i++){
		counts[divisors[data][i]]--;
		if(counts[divisors[data][i]]>0)
			active[counts[divisors[data][i]]].insert(divisors[data][i]);
		active[counts[divisors[data][i]]+1].erase(divisors[data][i]);
	}
}
int main(){
	for(int i=2;i<MAX;i++){
		if(!primes[i]){
			for(int j=2*i;j<MAX;j+=i){
				primes[j]=1;
			}
		}
		else{
			for(int j=i;j<MAX;j+=i){
				divisors[j].push_back(i);
			}
		}
	}
	cin>>t;
	while(t--){
		listSize=0;
		fill(counts,counts+MAX,0);
		for(int i=1;i<MAX;i++)
			active[i].clear();
		cin>>n;
		for(int _=0;_<n;_++){
			scanf("%s",type);
			if(type[0]=='U'){
				scanf("%s%d",type,&data);
				if(type[0]=='A'){
					add(data);
				}
				else{
					remove(data);
				}
			}
			else{
				if(listSize==0){
					puts("-1");
					
				}
				else{
					
					puts("1");
					for(itr=active[listSize].begin();itr!=active[listSize].end();itr++){
						printf(" %d",*itr);
					}
					puts("\n");
					
				}
			}
		}
	}
	return 0;
}
