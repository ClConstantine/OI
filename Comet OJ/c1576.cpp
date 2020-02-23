#include <iostream>
#include <cstring>

using namespace std;

int mmin=9;
const int mmax=1000000 + 10;
char s[mmax];
int main()
{
    cin>> (s+1);
    int len = strlen(s+1);
    for(int i=1;i<=len;i++){
        mmin=min(s[i]-'0',mmin);
    }
    cout<<(10+mmin-(s[len]-'0'))%10;
    return 0;
}
