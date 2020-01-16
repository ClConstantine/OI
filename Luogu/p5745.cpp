#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;using std::cerr;

const int mmax = 4e6 + 10;

int can[mmax];
int m,n;

int main(){

    cin>>n>>m;

    int f = 0,s,e,sum = 0,max = -1;
    for(int i=1;i<=n;i++){
        cin>>can[i];
    }    

    for(int i = 1;i<=n;i++){
        sum += can[i];
        while(sum > m){
            f++;
            sum -= can[f]; 
        }
        if(sum > max) {
            max = sum;
            s = f+1;
            e = i;
        }
    }
    cout<<s<<" "<<e<<" "<<max;
    return 0;
}