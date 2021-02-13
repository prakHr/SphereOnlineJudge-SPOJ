#include<bits/stdc++.h>
using namespace std;

const int me=100025;
const int INF=pow(2,30);

typedef struct node{
	int value;
	node *l,*r;
}node;

typedef node* pnode;

pnode Init(int value){
	pnode p=(pnode)malloc(sizeof(node));
	p->value=value;
	p->l=p->r=NULL;
	
}
int get(pnode &root){
	return root?root->value:-INF;
}
void relax(pnode &root){
	root->value=max(get(root->l),get(root->r));
}
void update(pnode &root,int low,int high,int pos,int value){
	if(!root)root=Init(high);
	
	if(low==high && low==pos){
		root->value=value;
		return;
	}
	
	int mid=(low+high)/2;
	
	if(pos <= mid)update(root->l,low,mid,pos,value);
	else update(root->r,mid+1,high,pos,value);
	
	if(!root->l)root->l=Init(mid);
	if(!root->r)root->l=Init(high);
	
	relax(root);
}
int query(pnode &root,int low,int high,int pos){
	if(low==high)
		return low;
	if(!root)root=Init(high);
	
	int mid=(low+high)/2;
	
	if(!root->l)root->l=Init(mid);
	if(!root->r)root->r=Init(high);
	
	if(get(root->l)>=pos)return query(root->l,low,mid,pos);
	return query(root->r,mid+1,high,pos);
	
}
int n,type,x;
pnode root;

int main(){
	root=NULL;
	cin>>n;
	while(n--){
		cin>>type>>x;
		if(type==1){
			int p=query(root,1,INF,x);
			update(root,1,INF,p,-INF);
			cout<<p<<endl;
		}
		else update(root,1,INF,x,x);
	}
	return 0;
}
