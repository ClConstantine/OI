#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>

using std::cin;using std::cout;using std::cerr;using std::endl;

const int mmax = 5e5;
int st[mmax + 10],fa[mmax + 10],tree[mmax + 10],head[mmax + 10],next[mmax + 10],ver[mmax + 10];
long long k[mmax + 10],add[mmax + 10];
int n,top,tot;
char c;
long long ans;

void ad(int x,int y){
    ver[++tot] = y;
    next[tot] = head[x];
    head[x] = tot; 
}

void dfs(int x){
    bool f = 0;int t;
    
    if(tree[x] == 1){
        st[++top] = x;
    }
    else if(tree[x] == -1){
        if(top){
            t = st[top];
            top--;
            f = 1;
            add[x] = add[fa[t]] + 1;
        }
    }
    
    k[x] = k[fa[x]] + add[x];

    for(int i = head[x];i;i = next[i]){
        dfs(ver[i]);
    }

    if(f){
        st[++top] = t;
    }
    else if(top) top--;
    return ;
}

int main(){

    std::ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i = 1;i <= n;++i){
        cin>>c;
        if(c =='('){
            tree[i] = 1;
        }
        else{
            tree[i] = -1;
        }
    }

    for(int i = 2;i <= n;++i){
        cin>>fa[i];
        ad(fa[i],i);
    }

    dfs(1);

    for(long long i = 1;i <= n;++i){
        ans ^= (i * k[i]);
    }
    cout<<ans;

    return 0;
}