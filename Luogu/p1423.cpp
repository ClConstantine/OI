#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    double ans=0,n;
    int bu=0;
    cin>>n;
    for(double i=2;i>0;i*=0.98){
        ans+=i;
        bu++;
        if(ans>=n) break;
    }
    cout<<bu;
    return 0;
}
