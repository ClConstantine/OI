#include <iostream>
#include <cstdio>
#include <map>

using std::cin;using std::cout;using std::endl;using std::cerr;

long long n,m;
const long long mod=1000000007;
std::map <long long,long long> can;
long long dfs (long long x){
    if(x==1) return n;
    if(can.count(x)){
        return can[x];
    }
    if(x%2){
        can[x]=(dfs(x/2)*dfs(x/2+1)-n)%mod;
        return can[x];
    }
    else {
        can[x]=(dfs(x/2)*dfs(x/2)-2)%mod;
        return can[x];
    }
}

int main(){
    cin>>n>>m;
    n%=mod;
    cout<<dfs(m);
    return 0;
}
