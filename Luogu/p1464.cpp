#include <iostream>
#include <cstdio>

using std::cin;using std::endl;using std::cout;

bool book[25][25][25];
long long can[25][25][25];
long long a,b,c;

long long w(int a,int b,int c){
    
    if(a<=0||b<=0||c<=0) return 1;
    else if(a>20||b>20||c>20){
        return w(20,20,20);
    }
    else if(book[a][b][c]) return can[a][b][c];
    else if(a<b&&b<c){
        can[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
        book[a][b][c]=1;
        return can[a][b][c];
    }
    else {
        can[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
        book[a][b][c]=1;
        return can[a][b][c];  
    }
    return 0;
}
int main(){
    cin>>a>>b>>c;
    while(1){
        if(a==-1&&b==-1&&c==-1) break;
        
        if(a<=0||b<=0||c<=0){
            printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,1);

        }
        else if(a>20||b>20||c>20){
            printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(20,20,20));
        }
        else printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
        cin>>a>>b>>c;
    }

    return 0;
}
