#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using std::cin;using std::cout;using std::endl;using std::cerr;

const int mmax = 1e5;
int n,m;
int op[mmax + 10],T[mmax + 10],t1,t0,ans,sum;
char s[10];

int geta(int bit,int ans){
    for(int i = 1;i <= n;++i){
        int t = (T[i] >> bit) & 1; 
        if(op[i] == 1) ans |= t;
        else if(op[i] == 2) ans ^= t;
        else ans &= t;
    }
    return ans;
}

int main(){
    
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    
    for(int i = 1;i <= n;++i){
        cin>>s>>T[i];
        switch(s[0]){
            case 'O':
                op[i] = 1;
                break;
            case 'X':
                op[i] = 2;
                break;
            case 'A':
                op[i] = 3;
                break;
        }
    }
    
    for(int bit = 30;bit >= 0;--bit){
        t0 = geta(bit,0);
        t1 = geta(bit,1);
        if(sum + (1<<bit) <= m && t1 > t0){
            sum += (1<<bit);
            ans += (t1<<bit);
        }
        else ans += (t0<<bit); 
    }
    
    cout<<ans;

    return 0;
}