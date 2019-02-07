#include <iostream>
#include <cstdio>

using std::cin; using std::cout; using std::endl; using std::cerr;
typedef long double ldd;

ldd sum=0;

void getsum(ldd a) {
    sum += a * 1000000;
}
int main(){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    ldd temp;
    while (cin >> temp && temp) {
        getsum(temp);
    }
    printf("%.5Lf",sum/1000000);
    return 0;
}
