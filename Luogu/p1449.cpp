#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a;
int mm[1000];
int now;
int s(){
    int i=0;
    while((a=getchar())!='@'){
        if(a<='9'&&a>='0') {
            now=now*10+a-'0';
        }
        else if(a=='.'){
            mm[i]=now;
            i++;
            now=0;
        }
        switch(a){
            case '+':
                mm[i-2]=mm[i-2]+mm[i-1];
                i--;
                break;
            case '-':
                mm[i-2]=mm[i-2]-mm[i-1];
                i--;
                break;
            case '*':
                mm[i-2]=mm[i-2]*mm[i-1];
                i--;
                break;
            case '/':
                mm[i-2]=mm[i-2]/mm[i-1];
                i--;
                break;
        }
    }
    return mm[0];
}
int main()
{
    cout<<s();
    return 0;
}
