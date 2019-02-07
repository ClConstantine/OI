#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int temp=0;
    int flag=1;
    string s;
    cin>>s;
    for(int i=0;i<12;i++){
        if(s[i]>='0'&&s[i]<='9'){
            temp+=(flag++)*(s[i]-'0');
        }
    }
    if(temp%11==(s[12])-'0'||(temp%11==10&&s[12]=='X')) cout<<"Right"<<endl;
    else {
        for(int i=0;i<12;i++){
            cout<<s[i];
        }
        if(temp%11!=10) cout<<temp%11<<endl;
        else cout<<'X';
    }
    return 0;
}
