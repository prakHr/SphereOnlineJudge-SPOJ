#include<bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <utility>
using namespace std;

const int MAX=100005;

int N,K;
long long result=0;
map<string,long long> m;
vector<long long> costs;

int main(){
	while(cin>>N>>K){
		if(cin.eof())break;
		result=0;
		m.clear();
		costs.clear();
		for(int i=0;i<N;i++)
		{
			string word;
			int value;
			cin>>word>>value;
			m[word]+=value;
		}
		std::map<std::string, long long>::iterator it = m.begin();
		while(it!=m.end()){
			costs.push_back(it->second);
			it++;	
		}
		sort(costs.begin(),costs.end(),greater<long long>());
		for(int i=0;i<costs.size();i++){
			if(K>0){
				result+=costs[i];
				K--;
			}
		}
		cout<<result<<endl;
	}
	return 0;
}

