#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,num1,pri1,num2,pri2,num3,pri3,w1,w2,w3;
    cin>>n>>num1>>pri1>>num2>>pri2>>num3>>pri3;
    w1=ceil(1.0*n/num1)*pri1;
    w2=ceil(1.0*n/num2)*pri2;
    w3=ceil(1.0*n/num3)*pri3;
    if(w1>w2)w1=w2;
    if(w1>w3)w1=w3;
    cout<<w1;
    return 0;
}
