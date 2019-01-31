#include<iostream>
#include<cstring>
using namespace std;
char a[255];
char b[21];
char *top=b;
void push(char a){
    *top=a;
    top++;
}
void out(){
    top--;
    *top=0;
}
int main()
{
    int bo=1,i;
    cin>>a;
    for(i=0;i<255;i++){
        if(a[i]=='(') push(a[i]);
        if(a[i]==')'){
            if(top==b){
                bo=0;
            }
            else out();
        }
        if(a[i]=='@') break;
    }
    if(bo==0) cout<<"NO";
    else if(b[0]=='(')cout<<"NO";
    else cout<<"YES";
    return 0;
}
