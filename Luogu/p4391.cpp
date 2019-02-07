#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using std::cin;using std::cout;using std::endl;
char s[1000010];int kmp[1000010];
int j=0,len;
int main(){
    
    cin>>len>>s+1;
    kmp[0]=kmp[1]=0;
    for(int i=2;i<=len;i++){
        while(j&&s[i]!=s[j+1]) j=kmp[j];
        if(s[i]==s[j+1]) j++;
        kmp[i]=j;
    }
    cout<<len-kmp[len];
    return 0;
}  
