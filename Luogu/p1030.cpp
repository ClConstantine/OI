#include <iostream>
#include <cstdio>
#include <cstring>

using std::cin;using std::cout;using std::endl;using std::string;

string mid,suf;
int len;

void dfs(string mid,string suf){
    if(suf.size()){
        char ch = suf[suf.size()-1];
        cout<<ch;
        int k= mid.find(ch);
        dfs(mid.substr(0,k),suf.substr(0,k));
        dfs(mid.substr(k+1),suf.substr(k,suf.size()-k-1));
    }
}

int main(){

    cin>>mid>>suf;

    dfs(mid,suf);

    return 0;
}
