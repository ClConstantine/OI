#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    double w;
    cin>>n;
    if(n<=150) w=n*0.4463;
    else if(n>150&&n<=400) w=150*0.4463+(n-150)*0.4663;
    else if(n>400) w=150*0.4463+250*0.4663+(n-400)*0.5663;
    printf("%.1f",w);
    return 0;
}
