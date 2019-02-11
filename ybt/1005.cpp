#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int x,a,y,b;
    cin>>x>>a>>y>>b;
    double add=1.0*((b*y)-(a*x))/(b-a);
    printf("%.2f",add);
    return 0;
}
