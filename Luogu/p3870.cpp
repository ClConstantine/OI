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

const int mmax = 1e5;
int can[mmax + 10];
int tot = 0,opt,l,r,n,t,m;
char s;

struct node{
	node *ls,*rs;
	int l,r,n0,n1;
	bool lazy;
	int dis(){
		return r-l+1;
	}
}T[mmax*4 + 10],*root;

node* create(){
	return &T[++tot];
}

void pushdown(node* cur){
	cur->lazy = 0;
	
	if(cur->dis() == 1) return;
	
	cur->ls->lazy ^= 1;
	cur->rs->lazy ^= 1;
	std::swap(cur->ls->n1,cur->ls->n0);
	std::swap(cur->rs->n1,cur->rs->n0);
}

void pushup(node* cur){
	cur->n0 = cur->ls->n0 + cur->rs->n0;
	cur->n1 = cur->ls->n1 + cur->rs->n1;
}

void build(node *cur,int l,int r){
	cur->l = l;cur->r = r;
	
	if(cur->dis()==1){
		if(can[l]==0){
			cur->n0 = 1;
		}
		else cur->n1 = 1;
		return ;  
	}

	cur->ls = create();cur->rs = create();
	build(cur->ls,l,(l+r)/2);
	build(cur->rs,(l+r)/2+1,r);
	pushup(cur);
}

int getsum(node* cur,int l,int r){
	if(cur->l > r||cur->r < l){
		return 0;
	}
	if(cur->l >= l&&cur->r <= r){
		return cur->n1;
	}
	if(cur->lazy) pushdown(cur);

	return getsum(cur->ls,l,r)+getsum(cur->rs,l,r);

}

void change(node*cur,int l,int r){
	if(cur->l > r||cur->r < l){
		return;
	}
	if(cur->l >= l&&cur->r <= r){
		cur->lazy ^= 1;
		std::swap(cur->n0,cur->n1);
		return ;
	}
	if(cur->lazy) pushdown(cur);
	change(cur->ls,l,r),change(cur->rs,l,r);
	pushup(cur);
}

void test(node* cur){
	if(cur->dis() == 1){
		cout<<cur->n1;
		return;
	}
	if(cur->lazy) pushdown(cur);
	test(cur->ls),test(cur->rs);
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	memset(can,0,sizeof(can));

	root = create();
	build(root,1,n);

	for(int i = 0;i < m;i++){
		cin>>opt>>l>>r;
		if(opt == 1){
			cout<<getsum(root,l,r)<<endl;
		}
		else{
			change(root,l,r);
			/*test(root);
			cout<<endl;*/
		}
	}

	return 0;
}