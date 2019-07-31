#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using std::cin;using std::cout;using std::cerr;using std::endl;

int can[25][25];
int ans=0;

struct feild{
    int x,y,num;
}ma[600];

bool rule(feild a,feild b){
    if(a.num>b.num) return 1;
    if(a.num==b.num) {
        if(a.x<b.x) return 1;
        if(a.x==b.x) {
            if(a.y<b.y) return 1;
        }
    }
    return 0;
}

int main()
{

    cin.tie(0);
	std::ios::sync_with_stdio(false);


    int N,M,step;
    cin>>M>>N>>step;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            cin>>can[i][j];
            ma[(i-1)*N+j].x=i;
            ma[(i-1)*N+j].y=j;
            ma[(i-1)*N+j].num=can[i][j];
        }
    }

    std::sort(ma+1,ma+M*N+1,rule);

    int f=1,fx=0,fy=0;
    if(step<=2){
        cout<<0;
        return 0;
    }

    fx=1;fy=ma[f].y;
    step--;

    while(step){

        if(step<1+ma[f].x+abs(fx-ma[f].x)+abs(fy-ma[f].y)) break;

        step-=abs(fx-ma[f].x)+abs(fy-ma[f].y);
        fx=ma[f].x;fy=ma[f].y;
        step--;
        ans+=ma[f].num;

        f++;
    }
    cout<<ans;
    return 0;
}
