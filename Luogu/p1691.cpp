#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char can[1000];
int bo[30];
int cnt=0;
int N;
void sao(int x){
    if(x==N+1){
        cnt++;
        for(int i=1;i<=N;i++){
            cout<<can[i];
        }
        cout<<endl;
        return ;
    }
    for(int i=0;i<26;i++){
        if(bo[i]){
            can[x]=char(i+'a');
            bo[i]--;
            sao(x+1);
            bo[i]++;
        }
    }
    return ;
}
int main (){
    string temp;
    cin>>N;
    getchar();
    cin>>temp;
    for(int i=0;i<temp.length();i++){
        bo[temp[i]-'a']++;
    }
    sao(1);
    cout<<cnt;
    return 0;
}
