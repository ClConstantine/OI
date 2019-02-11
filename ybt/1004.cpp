#include <iostream>

using namespace std;

int main()
{
    char c;
    cin>>c;
    for(int i=1;i<=3;i++){
        for(int j=3-i;j>0;j--){
            cout<<' ';
        }
        for(int j=2*i-1;j>0;j--){
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}
