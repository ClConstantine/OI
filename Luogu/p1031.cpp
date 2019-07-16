#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using std::cin;using std::cout;using std::cerr;using std::endl;

int N;
int sum,ans,arv;
int can[110];

int main()
{

    cin.tie(0);
    std::ios::sync_with_stdio(false);

    cin>>N;

    for(int i=1;i<=N;i++){
        cin>>can[i];
        sum+=can[i];
    }

    arv=sum/N;

    for(int i=1;i<=N;i++){
        if(can[i]==arv) continue;
        can[i+1]+=can[i]-arv;
        ans++;
    }
     cout<<ans;
    return 0;
}
