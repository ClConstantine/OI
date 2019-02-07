#include <iostream>
#include <cstdio>
#include <cstring>
using std::cin;using std::cout;using std::cerr;using std::endl;

char a[100];
int main(){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    cin>>a+1;
    int len=strlen(a+1);
    int bo=-1,j;
    int boo=0;
    for(int i=1;i<=len;i++){
        if(a[i]=='.'){
            bo=0;
            j=i;
            break;
        }
        if(a[i]=='/'){
            bo=1;
            j=i;
            break;
        }
        if(a[i]=='%'){
            bo=2;
            break;
        }
    }
    if(bo==-1){
        for(int i=len;i>=1;i--){
            if(boo==0){
                if(a[i]=='0') continue;
                if(a[i]!='0') boo=1;
            }
            cout<<a[i];
        }
        if(boo==0) cout<<0;
    }
    else if(bo==0){
        for(int i=j-1;i>=1;i--){
            if(boo==0){
                if(a[i]=='0') continue;
                if(a[i]!='0') boo=1;
            }
            cout<<a[i];
        }
        if(boo==0) cout<<0;
        boo=0;
        cout<<'.';
        for(int i=j+1;i<=len;i++){
            if(boo==0){
                if(a[i]=='0') a[i]='*';
                else if(a[i]!='0') break;
            }
        }
        for(int i=len;i>=j+1;i--){
            if(a[i]!='*'){
                cout<<a[i];
                boo=1;
            }
        }
        if(boo==0) cout<<0;
    }
    else if(bo==1){
        for(int i=j-1;i>=1;i--){
            if(boo==0){
                if(a[i]=='0') continue;
                if(a[i]!='0') boo=1;
            }
            cout<<a[i];
        }
        if(boo==0) cout<<0;
        boo=0;
        cout<<'/';
        for(int i=len;i>=j+1;i--){
            if(boo==0){
                if(a[i]=='0') continue;
                if(a[i]!='0') boo=1;
            }
            cout<<a[i];
        }
    }
    else if(bo==2){
        for(int i=len-1;i>=1;i--){
            if(boo==0){
                if(a[i]=='0') continue;
                if(a[i]!='0') boo=1;
            }
            cout<<a[i];
        }
        if(boo==0){
            cout<<'0';
        }
        cout<<'%';
    }
    return 0;
}
