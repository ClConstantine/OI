#include <iostream>
#include <cstdio>
#include <algorithm>

using std::cin;using std::cout;using std::endl;using std::cerr;

bool book[30010];

struct q{
    int st,ed,t;
}can[5010];

bool rule(q a,q b){
    if(a.ed==b.ed){
        return a.st<b.st;
    }
    else return a.ed<b.ed;
}

int main(){
    std::ios::sync_with_stdio(false);
    cout.tie(0);

    //freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);

    int n,h,ans=0;
    cin>>n>>h;
    for(int i=1;i<=h;i++){
        cin>>can[i].st>>can[i].ed>>can[i].t;
    }

    std::sort(can+1,can+h+1,rule);
    /*for(int i=1;i<=h;i++){
        cout<<can[i].st<<' '<<can[i].ed<<endl;
    }*/

    for(int i=1;i<=h;i++){
        for(int j=can[i].st;j<=can[i].ed;j++){
            
            if(can[i].t==0){
                break;
            }
            
            if(book[j]){
                can[i].t--;
            }
        }
        for(int j=can[i].ed;;j--){
            if(can[i].t==0) break;
            if(book[j]){
                continue;
            }
            book[j]=1;
            ans++;
            can[i].t--;
        }
    }
    cout<<ans;
    return 0;
}
