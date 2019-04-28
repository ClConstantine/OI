#include <iostream>
#include <cstdio>
using std::cin;using std::cout;using std::endl;
int book[1010];
int main(){

    int n;
    cin>>n;
    book[2]=2;book[1]=1;
    for(int i=3;i<=n;i++){
        for(int j=1;j<=i/2;j++){
            book[i]+=book[j];
        }
        book[i]++;
    }
    cout<<book[n];
    return 0;
}
