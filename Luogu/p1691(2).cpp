#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
char ch[510];
bool bo[510];
int N,cnt;
int main()
{
    cin>>N;
    cin>>ch;
    sort(ch,ch+N);
    do{
        puts(ch);
        cnt++;
    }while(next_permutation(ch,ch+N));
    cout<<cnt;
    return 0;
}
