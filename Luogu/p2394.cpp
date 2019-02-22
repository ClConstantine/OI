#include <iostream>
#include <cstdio>

using std::cin; using std::cout; using std::endl; using std::cerr;


typedef long double LD;

int main(){
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    LD temp;
    scanf("%17Lf",&temp);
    printf("%.8Lf",temp/23);

    return 0;
}
