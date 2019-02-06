#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int can[500100],b[500100],C[500010],mark[500010];
int n;
int lowbitF(int x){
    return (x)&(-x);
}
int sumF(int x){
    int temp=0;
    for(int i=x;i>0;i-=lowbitF(i)){
        temp+=C[i];
    }
    return temp;
}
void addF(int x){
    for(int i=x;i<=n;i+=lowbitF(i)){
        C[i]++;
    }
}
int main(){
    int In;
    long long ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&can[i]);
        b[i]=can[i];
    }
    sort(b,b+n);
    In=unique(b,b+n)-b+1;
    for(int i=0;i<n;i++){
        mark[i]=n-(lower_bound(b,b+In,can[i])-b+1)+1;
    }
    for(int i=0;i<n;i++){
        addF(mark[i]);
        ans+=sumF(mark[i]-1);
    }
    cout<<ans;
    return 0;
}
