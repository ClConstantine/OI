#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;using std::cerr;
typedef long long ll;
const int MMAX=100000;

struct node{
	int l,r;
	ll sum,tag;
	node *lson,*rson;
	int dis(){
		return (r-l+1);
	}
}T[MMAX*4],*root;
ll a[MMAX+10];

int cnt=0,L,R,ADD;

node* create(){
	return &T[cnt++];
}

void pushup(node* cur){
	cur->sum=cur->lson->sum+cur->rson->sum;
}

void pushdown(node* cur){
	cur->lson->tag+=cur->tag;
	cur->rson->tag+=cur->tag;
	cur->lson->sum+=cur->lson->dis() * cur->tag;
	cur->rson->sum+=cur->rson->dis() * cur->tag;
	cur->tag=0;
}

void build(node* cur,int l,int r){
	cur->l=l;cur->r=r;
	if(l==r){
		cur->sum=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	cur->lson=create();
	cur->rson=create();
	build(cur->lson,l,mid);
	build(cur->rson,mid+1,r);
	pushup(cur);
}

void add(node* cur){
	if(cur->l>R||cur->r<L) return ;
	if(L<=cur->l&&cur->r<=R){
		cur->tag+=ADD;
		cur->sum+=cur->dis()*ADD;
		return ;
	}
	pushdown(cur);
	add(cur->lson);
	add(cur->rson);
	pushup(cur);
}
ll getsum(node* cur){
	if(cur->l>R||cur->r<L) return 0;
	if(L<=cur->l&&cur->r<=R){
		return cur->sum;
	}
	pushdown(cur);
	return getsum(cur->lson)+getsum(cur->rson);
}
int main(){
	std::ios::sync_with_stdio(false);
    cout.tie(0);
	int n,m;
	cin>>n>>m;
	int opt;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	root=create();
	build(root,1,n);
	for(int i=1;i<=m;i++){
		cin>>opt;
		if(opt==1){
			cin>>L>>R>>ADD;
			add(root);
		}
		else{
			cin>>L>>R;
			cout<<getsum(root)<<endl;
		}
	}
	return 0;
}
