#include <iostream>
#include <cstdio>
#include <cstring>

using std::cin;using std::cout;using std::endl;

struct node{
    char ans;
    node *ls,*rs;
}T[26*5],*root;

int cnt;

node* create(){
    return &T[cnt++];
}

void build(node *cur,char i,char j,char k){
    if(cur->ans!=i){
        if(cur->ls!=NULL)
            build(cur->ls,i,j,k);
        if(cur->rs!=NULL)
            build(cur->rs,i,j,k);
        return ;
    }

    if(j!='*'){
        cur->ls=create();
        cur->ls->ans=j;
    }
    if(k!='*'){
        cur->rs=create();
        cur->rs->ans=k;
    }
}

void write(node* cur){
    cout<<cur->ans;
    if(cur->ls!=NULL) write(cur->ls);
    if(cur->rs!=NULL) write(cur->rs);
}

int main(){
    char x,y,z;
    int n;
    cin>>n;

    root=create();

    cin>>x>>y>>z;
    root->ans=x;
    build(root,x,y,z);  

    for(int i=1;i<n;i++){
        cin>>x>>y>>z;
        build(root,x,y,z);
    }

    write(root);

    return 0;
}
