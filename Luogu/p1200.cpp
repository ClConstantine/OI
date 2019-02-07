#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    int ufo=1,group=1;
    string s1,s2;
    cin>>s1>>s2;
    for(int i=s1.length()-1;i>=0;i--){
        ufo*=s1[i]-'A'+1;
    }
    for(int i=s2.length()-1;i>=0;i--){
        group*=s2[i]-'A'+1;
    }
    if((ufo%47)==(group%47))
        cout<<"GO";
    else cout<<"STAY";
    //cout<<s1[0];
    return 0;
    
}
