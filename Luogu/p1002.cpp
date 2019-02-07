#include <iostream>
#include <cstdio>
using namespace std;
long long map0[25][25];
int bo[25][25];
int main(){
    int N,M,x1,y1;
    cin>>N>>M;
    //cout<<N<<M<<endl;;
    cin>>x1>>y1;
    bo[x1][y1]=bo[x1+1][y1+2]=bo[x1-1][y1+2]=bo[x1+1][y1-2]=bo[x1-1][y1-2]=1;
    bo[x1+2][y1+1]=bo[x1-2][y1+1]=bo[x1+2][y1-1]=bo[x1-2][y1-1]=1;
    for(int i=0;i<=21;i++){
        if(bo[i][0])
            break;
        map0[i][0]=1;
    }
    for(int i=0;i<=21;i++){
        if(bo[0][i])
            break;
        map0[0][i]=1;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(!bo[i][j]){
                map0[i][j]=map0[i][j-1]+map0[i-1][j];
            }
            //cout<<i<<" "<<j<<" "<<map0[i][j]<<endl;
        }
    }
    cout<<map0[N][M];
    return 0;
}
