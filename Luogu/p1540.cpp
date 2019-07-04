#include <iostream>
#include <cstdio>
#include <queue>

using std::cin;using std::cout;using std::endl;

int N,M,temp;
int book[10000];
std::queue<int> q;
int len=0,ans=0;

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>M>>N;
    for(int i=0;i<N;i++){
        cin>>temp;

        if(book[temp]) continue;

        if(!book[temp]){
            if(len<M){
                book[temp]=1;
                q.push(temp);
                ans++;
                len++;
            }
            else {
                book[q.front()]=0;
                q.pop();
                book[temp]=1;
                q.push(temp);
                ans++;
            }
        }
    }
    cout<<ans;

    return 0;
}
