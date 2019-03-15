//score 100
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int b[5];
long long x,y;
int lead;
char c[5010];
char temp;

int main()
{
    freopen("robot.in","r",stdin);
    freopen("robot.out","w",stdout);

    gets(c);
    int ans=strlen(c);
    for(int i=0;i<ans;++i){
        if(c[i]=='N'){
            b[1]++;
        }
        else if(c[i]=='S'){
            b[1]--;
        }
        else if(c[i]=='W'){
            b[2]--;
        }
        else b[2]++;
    }

    scanf("%d",&lead);
    int mod=lead/ans;

    y=mod*b[1];
    x=mod*b[2];

    for(int i=0;i<lead%ans;++i){
        if(c[i]=='N'){
            y++;
        }
        else if(c[i]=='S'){
            y--;
        }
        else if(c[i]=='W'){
            x--;
        }
        else x++;
    }
    printf("%lld %lld",x,y);
    return 0;
}
