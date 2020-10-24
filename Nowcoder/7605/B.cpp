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

#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = a;i >= b;--i)

const int mmax = 1e5;
int n,m,L,R;
int ans[15],d[15];


struct op
{
	int l,r;
}opt[mmax + 10];

struct node
{
	int l,r;
	node *ls,*rs;
	int len[15];
}T[mmax * 4 + 10],*root;

int tot = 0;

node* create(){
	return &T[++tot];
}

void deal(int a[],int b[],int c[]){
	rep(i,0,9){
		d[i] = a[b[i]];
	}
	rep(i,0,9){
		c[i] = d[i];
	}
}

void set(int x[]){
	rep(i,0,9){
		x[i] = i;
	}
}

void build(node* cur,int l,int r){
	if(l > r) return ;
	
	cur->l = l;cur->r = r;
	set(cur->len);

	if(l == r){
		std::swap(cur->len[opt[l].l],cur->len[opt[l].r]);
		return;
	}

	cur->ls = create();
	cur->rs = create();

	int mid = (l + r) >> 1;

	build(cur->ls,l,mid);
	build(cur->rs,mid + 1,r);

	deal(cur->ls->len,cur->rs->len,cur->len);
}

void query(node* cur,int ans[]){
	if(cur->r < L || cur->l > R) return ;
	if(L <= cur->l && cur->r <= R){
		deal(ans,cur->len,ans);
		return;
	}
	query(cur->ls,ans);
	query(cur->rs,ans);

}

int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	rep(i,1,n){
		cin>>opt[i].l>>opt[i].r;
	}

	root = create();

	build(root,1,n);

	rep(i,1,m){
		set(ans);
		cin>>L>>R;
		query(root,ans);
		rep(i,0,9){
			cout<<ans[i]<<' ';
		}
		cout<<endl;
	}


	return 0;
}