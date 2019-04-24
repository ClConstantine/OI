#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using std::cin;using std::cout;using std::endl;

int can[30],mmax;
char a[200];

int main(){
    for(int i=1;i<=4;i++){
        gets(a);
        int n=strlen(a);
        for(int i=0;i<n;i++){
            if(a[i]>='A'&&a[i]<='Z'){
                can[a[i]-'A'+1]++;
            }
        }
    }

    for(int i=1;i<=26;i++){
        mmax=std::max(mmax,can[i]);
    }

    while(mmax){
        for(int i=1;i<=25;i++){
            if(mmax<=can[i]){
                cout<<'*';
            }
            else cout<<' ';
            cout<<' ';
        }
        if(mmax<=can[26]){
            cout<<'*';
        }
        else cout<<' ';
        cout<<endl;
        mmax--;
    }

    for(int i=1;i<=25;i++){
        cout<<char(int('A')+i-1)<<' ';
    }
    cout<<'Z';
    return 0;
}
