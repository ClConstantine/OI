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

const int mmax = 2e5;

int n,m,a[mmax + 10],num,x,y,k;
std::vector<int> vec;
struct node
{
	node *ls,*rs;
	int l,r,sum;
}T[mmax * 40],*root[mmax + 10];
int tot = 0;

bool cmp(int a,int b){
	return a < b; 
}

void deal(){
	std::sort(vec.begin(),vec.end(),cmp);
	vec.erase(std::unique(vec.begin(),vec.end()),vec.end());
}

int findid(int x){
	return std::lower_bound(vec.begin(),vec.end(),x) - vec.begin() + 1;
}

node* create(){
	return &T[tot++];
}

void build(node* cur,int l,int r){
	cur->l = l;cur->r = r;
	if(l == r){
		return ;
	}

	int mid = (l + r) >> 1;

	cur->ls = create();
	cur->rs = create();
	build(cur->ls,l,mid);build(cur->rs,mid + 1,r);
}

void update(node* cur,node* oldcur,int pos){
	cur->l = oldcur->l,cur->r = oldcur->r;

	if(cur->l == cur->r){
		cur->sum = oldcur->sum + 1;
		// cout<<cur->l<<' '<<cur->sum<<endl;
		return;
	}

	cur->ls = create();
	cur->rs = create();

	int mid = (cur->l + cur->r) >> 1;
	if(pos > mid) {
		cur->ls = oldcur->ls;
		update(cur->rs,oldcur->rs,pos);
	}
	else{
		cur->rs = oldcur->rs;
		update(cur->ls,oldcur->ls,pos);
	}

	cur->sum = cur->ls->sum + cur->rs->sum;
}

int query(node* cur,node* oldcur,int k){
	// cout<<cur->l<<' '<<cur->r<<endl;
	if(cur->l == cur->r){
		return cur->l;
	}
	int sum = cur->ls->sum - oldcur->ls->sum;

	if(sum >= k){
		return query(cur->ls,oldcur->ls,k);
	}
	else{
		return query(cur->rs,oldcur->rs,k - sum);
	}
}


int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	rep(i,1,n){
		cin>>a[i];
		vec.push_back(a[i]);
	}
	deal();
	num = vec.size();
	root[0] = create();

	build(root[0],1,num);

	rep(i,1,n){
		root[i] = create();
		update(root[i],root[i - 1],findid(a[i]));
		// cout<<root[i]->sum<<endl;
	}

	rep(i,1,m){
		cin>>x>>y>>k;
		cout<<vec[query(root[y],root[x - 1],k) - 1]<<endl;
	}



	return 0;
}