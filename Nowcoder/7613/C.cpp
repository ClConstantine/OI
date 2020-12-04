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

int rk[mmax + 10],n,q,f[mmax + 10];
int ql,qr,qk;
struct point
{
	int id;
	char s[20];
}que[mmax + 10];

std::vector<char> vec;

bool cmp(point a,point b){
	int f = 0;
	while(a.s[f] != '\0'){
		if(b.s[f] == '\0' || a.s[f] > b.s[f]){
			return 0;
		}
		if(a.s[f] < b.s[f]){
			return 1;
		}
		f++;
	}
	return 1;
}

struct node
{
	int l,r,num;
	node *ls,*rs;
}T[mmax * 40 + 10],*root[mmax + 10];

int tot = 0;

node* create(){
	return &T[++tot];
}

void build(node* cur,int l,int r){
	cur->l = l;cur->r = r;
	if(l == r) return;

	int mid = (l + r) >> 1;
	cur->ls = create();cur->rs = create();
	build(cur->ls,l,mid);build(cur->rs,mid + 1,r);
}

void update(node* cur,node* oldcur,int k){
	cur->l = oldcur->l;cur->r = oldcur->r;

	// cout<<cur->l<<' '<<cur->r<<' '<<cur->num<<endl;

	if(cur->l == cur->r){
		cur->num = oldcur->num + 1;
		return ;
	}
	cur->ls = create(),cur->rs = create();

	if(k > oldcur->ls->r){
		cur->ls = oldcur->ls;
		update(cur->rs,oldcur->rs,k);
	}
	else{
		cur->rs = oldcur->rs;
		update(cur->ls,oldcur->ls,k);
	}
	cur->num = cur->ls->num + cur->rs->num;
	// cout<<cur->l<<' '<<cur->r<<' '<<cur->num<<endl;
}

int query(node* cur,node* oldcur,int k){
	if(cur->l == cur->r){
		return cur->l;
	}
	
	int temp = cur->ls->num - oldcur->ls->num;
	if(k >temp){
		return query(cur->rs,oldcur->rs,k - temp);
	}
	else{
		return query(cur->ls,oldcur->ls,k);
	}

}


int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("test3.in","r",stdin);
	// freopen("test3.out","w",stdout);

	cin>>n>>q;

	rep(i,1,n){
		cin>>que[i].s;
		que[i].id = i;
	}

	std::sort(que + 1,que + 1 + n,cmp);



	rep(i,1,n){
		rk[que[i].id] = i;
	}

	rep(i,0,n){
		root[i] = create();
	}

	build(root[0],1,n);

	rep(i,1,n){
		// cout<<rk[i]<<endl;
		update(root[i],root[i - 1],rk[i]);
		// cout<<"ok"<<endl;
	}

	rep(i,1,q){
		cin>>ql>>qr>>qk;
		// cout<<query(root[qr],root[ql - 1],qk)<<endl;
		if(qk > qr - ql + 1) cout<<-1<<endl; 
		else cout<<que[query(root[qr],root[ql - 1],qk)].s<<endl;
	}

	return 0;
}