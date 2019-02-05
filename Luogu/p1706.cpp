#include<iostream>
#include<cstdio>
using namespace std;
int N;
int a[10],book[10];
void bfs(int n){
    if(n==N+1){
        for(int i=1;i<N;i++){
            printf("%5d",a[i]);
        }
        printf("%5d\n",a[N]);
        return ;
    }
    else{
        for(int i=1;i<=N;i++){
            if(!book[i]){
                a[n]=i;
                book[i]=1;
                bfs(n+1);
                book[i]=0;
            }
        }
    }
}
int main()
{
    cin>>N;
    bfs(1);
    return 0;
}
