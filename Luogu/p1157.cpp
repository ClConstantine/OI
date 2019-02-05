#include<iostream>
#include<cstdio>
using namespace std;
int temp[21],book[21],N,n,r;
void dfs(int n){
    if(n==r+1){
        for(int i=1;i<=r;i++){
            printf("%3d",temp[i]);
        }
        printf("\n");
        return ;
    }
    else{
        for(int i=temp[n-1]+1;i<=N;i++){
            if(!book[i]){
                temp[n]=i;
                book[i]=1;
                dfs(n+1);
                book[i]=0;
            }
        }
    }
}
int main()
{
    cin>>N>>r;
    dfs(1);
    return 0;
}
