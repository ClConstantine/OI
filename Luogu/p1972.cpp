/*Luogu O2*/

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

const int mmax = 1e6;
int n,q,L,R,cnt,f;
int a[mmax + 10],ans[mmax + 10],vis[mmax + 10];

int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

struct task
{
	int l,r,id;
}ovo[mmax + 10];

bool cmp(task a,task b){
	if(a.r < b.r) return 1;
	return 0;
}

struct node
{
	node *ls,*rs;
	int ans,l,r;
	int dis(){
		return r - l + 1;
	}
}*root,T[mmax * 4 + 10];

void pushup(node* cur){
	cur->ans = cur->ls->ans + cur->rs->ans;
}

node* create(){
	return &T[cnt++];
}

void build(node* cur,int l,int r){
	cur->l = l,cur->r = r;
	if(l == r){
		return ;
	}
	int mid = (l + r) / 2;
	cur->ls = create();
	cur->rs = create();
	build(cur->ls,l,mid);
	build(cur->rs,mid + 1,r);
}

void change(node* cur,int color,int pos,int opt){
	if(cur->l > pos || cur->r < pos){
		return;
	}
	if(cur->dis() == 1){
			cur->ans = opt;
			vis[color] = cur->l;
		return ;
	}
	change(cur->ls,color,pos,opt);
	change(cur->rs,color,pos,opt);
	pushup(cur);
}

int query(node* cur){
	if(L > cur->r || R < cur->l){
		return 0;
	}
	if(L <= cur->l && R >= cur->r){
		return cur->ans;
	}
	return query(cur->ls) + query(cur->rs);
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	n = read();

	// freopen("test1.txt","w",stdout);

	rep(i,1,n){
		a[i] = read();
	}

	q = read();

	rep(i,1,q){
		ovo[i].l = read();
		ovo[i].r = read();
		ovo[i].id = i;
	}

	std::sort(ovo + 1,ovo + 1 + q,cmp);

	root = create();
	build(root,1,n);
	f = 0;

	rep(i,1,q){
		while(f < ovo[i].r){
			f++;
			if(vis[a[f]]) change(root,a[f],vis[a[f]],0);
			change(root,a[f],f,1);
		}

		L = ovo[i].l;
		R = ovo[i].r;
		ans[ovo[i].id] = query(root);
	}

	rep(i,1,q){
		printf("%d\n",ans[i]);	
	}


	return 0;
}
