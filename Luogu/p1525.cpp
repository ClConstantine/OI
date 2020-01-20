#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>

using std::cin;using std::cout;using std::cerr;using std::endl;

const int mmax=8000;
int n,tot = 0;
int can[mmax + 10],s;

struct node {
	node *ls,*rs;
	int l,r,w;

	int dis(){
		return r-l+1;
	}
}T[mmax*4+10],*root;

node* create(){
	return &T[++tot];
}

void pushup(node* cur){
	cur->w = cur->ls->w + cur->rs->w; 
}

void build(node* cur,int l,int r){
	cur -> l = l;cur -> r =r;

	if(l==r){
		cur->w = 1;
		return ;
	}
	cur -> ls = create();
	cur -> rs = create();
	build(cur->ls,l,(l+r)/2);
	build(cur->rs,(l+r)/2+1,r);
	pushup(cur);
}

void ser(int x,node* cur,int po){
	if(cur -> w == 1 && cur -> dis()==1){
		cur->w-=1;
		can[po] = cur->l; 
		return ;
	}

	if(x<=cur->ls->w){
		ser(x,cur->ls,po);
	}
	else ser(x-cur->ls->w,cur->rs,po);

	pushup(cur);
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	for(int i = 2;i <= n;i++){
		cin>>can[i];
	}

	root = create();
	build(root,1,n);

	for(s = n;s > 0;s--){
		ser(can[s]+1,root,s);
	}

	for(int i = 1;i<=n;i++){
		cout<<can[i]<<endl;
	}
	return 0;
}