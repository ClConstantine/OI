#include <iostream>
#include <cstdio>
#include <algorithm>

using std::cin;using std::cout;using std::endl;

int n,s,a,b,ans;

struct apple{
    int x,y;
}can[5010];

bool rule(apple a,apple b){
    if(a.y<b.y)  return 1;
    return 0;
}

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>s>>a>>b;
    
    for(int i=1;i<=n;++i){
        cin>>can[i].x>>can[i].y;
    }

    std::sort(can+1,can+1+n,rule);

    for(int i=1;i<=n;i++){
        if(a+b>=can[i].x){
            if(s>=can[i].y){
                ans++;
                s-=can[i].y;
            }
            else break;
        }
    }

    cout<<ans;
    return 0;
}
