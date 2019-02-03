#include <iostream>
#include <cstdio>

using std::cin; using std::cout; using std::endl; using std::cerr;

const int mmax=1000000;
int heap[mmax+10];
int flag=0;

void add(int i){
    if(i==1) return ;
    if(heap[i]<heap[i/2]){
        std::swap(heap[i],heap[i/2]);
        add(i/2);
    }
}
void del(int x){
    int now=x<<1;
    if(now<=flag){
        if(now+1<=flag&&heap[now+1]<heap[now])now++;
        if(heap[now]<heap[x]) {
            std::swap(heap[now],heap[x]);
            del(now);
        }
    }
}
int main(){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N,temp;
    cin>>N;
    for(int i=1;i<=N;i++){
        heap[i]=mmax+5;
    }
    for(int i=1;i<=N;i++){
        cin>>temp;
        if(temp==1){
            cin>>heap[++flag];
            add(flag);
        }
        else if(temp==2){
            cout<<heap[1]<<endl;
        }
        else {
            heap[1]=heap[flag];
            flag--;
            del(1);
        }
    }
    return 0;
}
