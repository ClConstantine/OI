#include <iostream>
#include <cstdio>

using std::cin; using std::cout; using std::endl; using std::cerr;

const int mmax=100000;
struct node {
    int ans;
    node *L,*R;
}T[mmax+10];

node* aget(int x){
    return &T[x];
}
void add(int i,int t,int p){
    if(p==0){
        T[i].R=aget(t);
        T[i].L=T[t].L;
        T[t].L->R=aget(i);
        T[t].L=aget(i);
        return ;
    }
    T[i].L=aget(t);
    T[i].R=T[t].R;
    T[t].R->L=aget(i);
    T[t].R=aget(i);
}
void del(int x){
    if(T[x].L!=NULL&&T[x].R!=NULL){
        T[x].L->R=T[x].R;
        T[x].R->L=T[x].L;
        T[x].R=NULL;
        T[x].L=NULL;
    }

}
int main(){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    node *head,*tail;
    int n,m,p,t;

    head=aget(0);
    head->R=aget(1);
    T[1].L=head;

    T[1].ans=1;

    tail=aget(mmax+5);
    tail->ans=mmax+5;
    T[1].R=tail;
    tail->L=aget(1);

    cin>>n;

    for(int i=2;i<=n;i++){
        cin>>t>>p;
        T[i].ans=i;
        add(i,t,p);
    }
    cin>>m;
    /*while(head->R->ans!=mmax+5){
        cout<<head->R->ans<<' ';
        head=head->R;
    }*/
    for(int i=1;i<=m;i++){
        cin>>t;
        del(t);
    }

    while(head->R->ans!=mmax+5){
        cout<<head->R->ans<<' ';
        head=head->R;
    }
    return 0;
}
