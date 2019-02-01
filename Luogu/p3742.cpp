#include<iostream>
#include<cstdio>
using namespace std;
char a[100],b[100],c[100];
int comp(char a[],char b[],int n){
    int i;
    for(i=0;i<n;i++){
        if(a[i]==b[i]) c[i]=char(a[i]+1);
        else if(a[i]<b[i]) break;
        else c[i]=b[i];
    }
    if(i==n) return 1;
    else return 0;
}
int main()
{
    int n;
    cin>>n;
    cin>>a;
    getchar();
    cin>>b;
    getchar();
    int bo=comp(a,b,n);
    if(bo)
    for(int i=0;i<n;i++){
        cout<<c[i];
    }
    else cout<<-1;
    return 0;
}
