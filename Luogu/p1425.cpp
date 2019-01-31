#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,t;
    cin>>a>>b>>c>>d;
    t=(c-a)*60+(d-b);
    cout<<t/60<<" "<<t%60;
    return 0;
}
