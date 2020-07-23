#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using std::cin;using std::cout;using std::endl;using std::cerr;

int n;
int T[10][10],t[10][10];
int ans,cnt;
char c;

void change(int x,int y){
    t[x][y] ^= 1;
    t[x - 1][y] ^= 1;
    t[x + 1][y] ^= 1;
    t[x][y - 1] ^= 1;
    t[x][y + 1] ^= 1;
    cnt++;
}


int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    
    while(n--){
        for(int i = 1;i < 6;++i){
            for(int j = 1;j < 6;++j){
                cin>>c;
                T[i][j] = c - '0';
            }
        }
        
        ans = -1;
        
        for(int s = 0;s < 32;++s){
            
            cnt = 0;
            
            for(int i = 1;i < 6;++i){
                for(int j = 1;j < 6;++j){
                    t[i][j] = T[i][j];
                }
            }
            
            for(int i = 0;i < 5;++i){
                if(((s>>i) & 1) == 1){
                   change(1,i+1); 
                }
            }
            for(int i = 2;i < 6;++i){
                for(int j = 1;j < 6;++j){
                    
                    if(!t[i-1][j]){
                        change(i,j);
                    }
                }
            }
            
            bool f = 1;

            for(int j = 1;j < 6;++j){
                if(!t[5][j]){
                   f = 0;
                }
            }
            
            if(f){
                if(cnt > 6) continue;
                else if(ans == -1) ans = cnt;
                else ans = std::min(ans,cnt);
            }
        }
        
        cout<<ans<<endl;
    }

    return 0;
}