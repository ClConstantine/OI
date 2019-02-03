#include <iostream>
#include <cstdio>
#include <queue>

using std::cin; using std::cout; using std::endl; using std::cerr;

std::priority_queue <int,std::vector<int>,std::greater<int> > heap;

int main(){
	cin.tie(0);
	std::ios::sync_with_stdio(false);
    int N,p,temp;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>p;
        if(p==1){
            cin>>temp;
            heap.push(temp);
        }
        else if(p==2){
            cout<<heap.top()<<endl;
        }
        else heap.pop();
    }
    return 0;
}
