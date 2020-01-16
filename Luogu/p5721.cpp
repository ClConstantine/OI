#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n,tot = 0;
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            tot += 1;
            if(tot>=10)cout<<tot;
            else cout<<0<<tot;
        }
        cout<<endl;
    }

    return 0;
}