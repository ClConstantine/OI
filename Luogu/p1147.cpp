#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long can[2000000+10],m;

int main()
{

    for(int i=1;i<=2000000+1;i++){
        can[i] = can[i-1] + i;
    }

    cin>>m;

    int f = 0;

    for(int i = 1;i<m;i++){
        if(can[i]-can[f]<m) continue;

        else if(can[i]-can[f] == m){
            cout<<f+1<<' '<<i<<endl;
            f++;
        }
        else if(can[i]-can[f]>m) {f++;i--;}
    }
    return 0;
}
