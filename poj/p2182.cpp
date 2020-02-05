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

const int mmax = 8000;
int can [mmax + 10];
int n,tot;

struct node
{
	int l,r,num;
	node *ls,*rs;

}*root,T[mmax * 4 + 10];

node* create(){
	return &T[++tot];
}

void pushup(node* cur){
	cur->num = cur->ls->num + cur->rs->num;
}

void build(node* cur,int l,int r){
	cur -> l = l;cur -> r = r;

	if(l==r){
		cur->num = 1;
		return ;
	}

	cur->ls = create();
	cur->rs = create();
	build(cur->ls,l,(l+r)/2);
	build(cur->rs,(l+r)/2+1,r);

	pushup(cur);
}

void query(node* cur,int x,int po){
	if(cur->l==cur->r){
		cur->num = 0;
		can[po] = cur->l;
		return ;
	}

	if(cur->ls->num >= x){
		query(cur->ls,x,po);
	}
	else{
		query(cur->rs,x-cur->ls->num,po);
	}

	pushup(cur);
}

int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	for(int i = 2;i <= n;++i){
		cin>>can[i];
	}

	can[1] = 0;

	root = create();
	build(root,1,n);

	for(int i = n;i > 0;--i){
		query(root,can[i]+1,i);
	}

	for(int i = 1;i <= n;++i){
		cout<<can[i]<<endl;
	}

	return 0;
}