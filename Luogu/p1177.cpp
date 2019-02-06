#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int n;
int Ican[100010];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&Ican[i]);
    }
    sort(Ican,Ican+n);
    for(int i=0;i<n;i++)
        printf("%d ",Ican[i]);
    return 0;
}
