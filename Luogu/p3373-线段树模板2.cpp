#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;using std::cerr;

typedef long long ll;
const int mmax=100000;
int L,R,cnt=0;
ll X,ADD;

struct node{
    ll sum,tag=0,mul=1;
    int l,r;
    node *ls,*rs;
    int dis(){
        return (r-l+1);
    }
}T[mmax*4],*root;

ll a[mmax+10];

node* create(){
    return &T[cnt++];
}

void pushup(node* cur){
    cur->sum=cur->ls->sum+cur->rs->sum;
    return ;
}

void build(node* cur,int l,int r){
    cur->l=l; cur->r=r;
    if(l==r){
        cur->sum=a[l] % X;
        return ;
    }
    cur->ls=create();
    cur->rs=create();
    int mid=(l+r)>>1;
    build(cur->ls,l,mid);
    build(cur->rs,mid+1,r);
    pushup(cur);
}

void add1(node*);
void add2(node*);
void pushdown(node*);
ll getsum(node*);

void pushdown(node* cur){
    cur->ls->mul=(cur->ls->mul*cur->mul) % X;
    cur->ls->tag=(cur->ls->tag*cur->mul+cur->tag)%X;
    cur->ls->sum=(cur->ls->sum*cur->mul+cur->tag*cur->ls->dis())%X;
    cur->rs->mul=(cur->rs->mul*cur->mul)%X;
    cur->rs->tag=(cur->rs->tag*cur->mul+cur->tag)%X;
    cur->rs->sum=(cur->rs->sum*cur->mul+cur->tag*cur->rs->dis())%X;
    cur->tag=0;
    cur->mul=1;
}

void add1(node* cur){
    if(cur->l>R||cur->r<L) return ;
    if(cur->l>=L&&cur->r<=R){
        cur->tag = (cur->tag + ADD) % X;
        cur->sum = (cur->sum + ADD * cur->dis()) % X;
        return ;
    }
    pushdown(cur);
    add1(cur->ls);add1(cur->rs);
    pushup(cur);
}

void add2(node* cur){
    if(cur->l>R||cur->r<L) return ;
    if(cur->l>=L&&cur->r<=R){
        cur->sum = (cur->sum * ADD) % X;
        cur->tag *= (ADD % X);
        cur->mul *= (ADD % X);
        return ;
    }
    pushdown(cur);
    add2(cur->ls),add2(cur->rs);
    pushup(cur);
}

ll getsum(node* cur){
    if(cur->r<L||R<cur->l){
        return 0;
    }
    if(L<=cur->l&&cur->r<=R){
        return cur->sum % X;
    }
    pushdown(cur);
    return getsum(cur->ls)+getsum(cur->rs) % X;
}

int main(){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    root=create();
    int n,m;
    cin>>n>>m>>X;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(root,1,n);
    int opt;
    for(int i=1;i<=m;i++){
        cin>>opt;
        if(opt==1){
            cin>>L>>R>>ADD;
            add2(root);
            //<<"ok1"<<endl;
        }
        else if(opt==2){
            cin>>L>>R>>ADD;
            add1(root);
            //cout<<"ok2"<<endl;
        }
        else {
            cin>>L>>R;
            cout<<getsum(root) % X<<endl;
            //cout<<"ok3"<<endl;
        }
    }
    return 0;
}
