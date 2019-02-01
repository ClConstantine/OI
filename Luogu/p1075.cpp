#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;;++i){
        if(!(n%i)) {printf("%d",n/i);break;}
    }
    return 0;
}
