#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using std::cin;using std::cout;using std::endl;

char name[100001][11];
bool book[100001];
int m,n,f,a,s;

void set(){
    if(f<=0) f+=n;
    else if(f>n)f-=n;
}

void move(int face,int step){
    if(face%2) f+=step;
    else f-=step;
    set();
}

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>book[i]>>name[i];
    }
    
    f=1;

    for(int i=0;i<m;i++){
        cin>>a>>s;
        move(book[f]+a,s);
    }
    cout<<name[f];

    return 0;
}
