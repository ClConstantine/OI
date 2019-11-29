#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using std::cin; using std::cout; using std::endl; using std::cerr;

struct q{
    int a,b;
}ques[10010];

int can[10010];

int n,h,R,a,b,t;

bool cmp(q a,q b){
    if(a.a<b.a) return 1;
    else if(a.a==b.a){
        if(a.b<b.b) return 1;
    }
    return 0;
}

int main(){

    cin.tie(0);
    std::ios::sync_with_stdio(false);

    cin>>n>>t>>h>>R;


    for(int i=1;i<=R;i++){
        cin>>a>>b;
        int l,r;
        l=std::min(a,b);
        r=std::max(a,b);
        ques[i].a=l;
        ques[i].b=r;
    }

    std::sort(ques+1,ques+1+R,cmp);


    for(int i=1;i<=R;i++){
        if(ques[i-1].a==ques[i].a&&ques[i-1].b==ques[i].b)continue;
        for(int j=ques[i].a+1;j<ques[i].b;j++){
            can[j]--;
        }
    }

    for(int i=1;i<=n;i++){
        cout<<can[i]+h<<endl;
    }
    return 0;
}
