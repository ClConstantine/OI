#include <iostream>
#include <cstdio>

using std::cin; using std::cout; using std::cerr; using std::endl; using std::min; using std::max;
typedef long long ll;
int L,R,ADD;
const int mmax=100000;
struct SR{
    int a[mmax+10];
    ll T[mmax*4],lazy[mmax*4];
    void build(int idx,int l,int r){
        if(l==r){
            T[idx]=a[l];
            return ;
        }
        int mid=(l+r)>>1;
        build(idx<<1,l,mid);
        build(idx<<1|1,mid+1,r);
        T[idx]=T[idx<<1]+T[idx<<1|1];
        return ;
    }
    void print(int idx,int l,int r){    //查看是否出错 
        if(l==r){
            cerr<<l<<" "<<r<<" "<<T[idx]<<' '<<lazy[idx]<<endl;
            return ;
        }
        int mid=(l+r)>>1;
        print(idx<<1,l,mid);
        print(idx<<1|1,mid+1,r);
        cerr<<l<<" "<<r<<" "<<T[idx]<<' '<<lazy[idx]<<endl;
    }
    void add(int idx,int l,int r){
        if(r<L||l>R){
            return ;
        }
        if(l==r){
            T[idx]+=ADD;
            return ;
        }
        else if(L<=l&&R>=r){
            lazy[idx]+=ADD;
            T[idx]+=(r-l+1)*ADD; 
            return ;
        }
        //else lazy 下放后处理
         int mid=(l+r)>>1;
         int lson=idx<<1,rson=(idx<<1)|1;
         lazy[lson]+=lazy[idx];
         lazy[rson]+=lazy[idx];
         T[lson]+=(mid-l+1)*lazy[idx];
         T[rson]+=(r-mid)*lazy[idx];
         lazy[idx]=0;

         add(lson,l,mid);
         add(rson,mid+1,r);

         T[idx]=T[lson]+T[rson];

         return ; 
    }
    long long getsum(int idx,int l,int r){
        if(L>r||R<l){
            return 0;
        }
        if(L<=l&&r<=R){
            return T[idx];
        }
        // lazy下放后处理
        int mid=(l+r)>>1;
        int lson=idx<<1;int rson=(idx<<1)|1;
        lazy[lson]+=lazy[idx];
        lazy[rson]+=lazy[idx];
        T[lson]+=(mid-l+1)*lazy[idx];
        T[rson]+=(r-mid)*lazy[idx];
        lazy[idx]=0;
        return getsum(lson,l,mid)+getsum(rson,mid+1,r);
    }
}TS;

int main (){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>TS.a[i];
    }
    TS.build(1,1,N);
    TS.print(1,1,N);
    int opt;
    for(int i=1;i<=M;i++){
        cin>>opt;
        if(opt==1){
            cin>>L>>R>>ADD;
            TS.add(1,1,N);
            //TS.print(1,1,N);
        }
        else {
            cin>>L>>R;
            cout<<TS.getsum(1,1,N)<<endl;
        }
    }
    return 0;
}
