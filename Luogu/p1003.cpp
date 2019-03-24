#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;

const int mmax=100000;
int a[mmax+10],b[mmax+10],c[mmax+10],d[mmax+10];

int main()
{

    std::ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    for(int i=0;i<N;++i){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    int x,y;
    cin>>x>>y;
    int i;
    for(i=N-1;i>=0;--i){
        if(x>=a[i]&&x<=a[i]+c[i]&&y>=b[i]&&y<=b[i]+d[i]){
            cout<<i+1;
            break;
        }
    }
    if(i==-1) cout<<-1;
    return 0;
}
