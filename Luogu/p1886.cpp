#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int mmax=1e6+10;
int can[mmax],q[mmax][2];

int main()
{
    int n,m,head=1,tail=2;

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>can[i];
    }
    q[head][0]=can[1];
    q[head][1]=1;

    if(m==1) cout<<can[1]<<' ';

    for(int i=2;i<=n;i++){
        if(i-q[head][1] >= m) head++;

        while(head<tail&&q[tail-1][0]>can[i]){
            tail--;
        }
        q[tail][0]=can[i];q[tail][1]=i;

        tail++;

        if(i<m) continue;

        cout<<q[head][0]<<' ';

    }

    cout<<endl;

    head = 1;tail = 2;
    q[head][0]=can[1];
    q[head][1]=1;

    if(m==1) cout<<can[1]<<' ';

    for(int i=2;i<=n;i++){
        if(i-q[head][1] >= m) head++;

        while(head<tail&&q[tail-1][0]<can[i]){
            tail--;
        }
        q[tail][0]=can[i];q[tail][1]=i;

        tail++;

        if(i<m) continue;
        cout<<q[head][0]<<' ';
    }

    return 0;
}
