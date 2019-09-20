#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using std::cin;using std::cerr;using std::cout;using std::endl;

char s[1000+10];
char st[10];
int main(){

    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int n,len,ans=0;

    cin>>n;

    st[1]='a';st[2]='c';st[3]='p';st[4]='t';st[5]='y';

    while(n--){
        int i=0;
        cin>>s+1;
        len=strlen(s+1);
        for(i=1;i<=5;i++){
            if(s[len-5+i]!=st[i]) break;
        }
        if(i==6) ans++;
    }

    cout<<ans;

    return 0;
}
