#include <iostream>
#include <cstdio>
#include <cstring>

using std::cin;using std::cout;using std::cerr;using std::endl;

char s[1000+100];
int N;

struct node {
    node *ls,*rs;
    int l,r;
    char ans;
    int len(){
        return r-l+1;
    }
}T[1024*10],*root;

int num;

node* create(){
    return &T[num++];
}

void pushup(node* cur){
    if(cur->len()==1){
        if(s[cur->l]=='0')
            cur->ans='B';
        else
            cur->ans='I';
        return ;
    }

    if(cur->ls->ans=='B'&&cur->rs->ans=='B'){
        cur->ans='B';
    }
    else if(cur->ls->ans=='I'&&cur->rs->ans=='I'){
        cur->ans='I';
    }
    else {
        cur->ans='F';
    }

    return ;
}

void build(node* cur,int l,int r){
    cur->l=l;cur->r=r;

    if(l==r){
        pushup(cur);
        return ;
    }
    cur->ls=create();
    cur->rs=create();
    build(cur->ls,l,(l+r)/2);
    build(cur->rs,(l+r)/2+1,r);
    pushup(cur);

}

void pre(node *cur){
    if(cur->l==cur->r){
        cout<<cur->ans;
        return ;
    }
    pre(cur->ls);
    pre(cur->rs);

    cout<<cur->ans;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    cin>>N;

    int get = 1<<N;

    cin>> s+1;

    root=create();

    build(root,1,get);

    pre(root);

    return 0;
}
