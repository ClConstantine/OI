#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int can[110],C[110],b[110],mark[110],ans[110];
int n;
int lowbit(int x){
    return x&(-x);
}
void add(int x){
    for(int i=x;i<n;i+=lowbit(i)){
        C[i]++;
    }
    return ;
}
int sum(int x){
    int temp=0;
    for(int i=x;i>0;i-=lowbit(i)){
        temp+=C[i];
    }
    return temp;
}
int main()
{
    int In;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>can[i];
        b[i]=can[i];
    }
    sort(b,b+n);
    In=unique(b,b+n)-b;
    for(int i=0;i<n;i++){
        mark[i]=lower_bound(b,b+In,can[i])-b+1;
        add(mark[i]);
        ans[i]=sum(mark[i]-1);
    }
    /*for(int i=0;i<n;i++){
        cout<<mark[i]<<" ";
    }
    cout<<In;*/
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
