#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>

using std::cin;using std::cout;using std::cerr;using std::endl;

#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = a;i >= b;--i)

int n,t;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	while(cin>>n && n){
		rep(i,1,n){
			cin>>t;
		}
		if(n == 1){
			if((t & 1) == 0){
				cout<<"YES"<<endl;
				continue;
			}
		}
		cout<<"NO"<<endl;
	}



	return 0;
}

/*


结论：当且仅当石子堆数为1堆，且石子数量为偶数时，Alice有必胜策略，否则一定是Bob获胜。

证明：Bob的策略为：若场上存在偶数堆石子，那么将这一堆取走奇数个，使其变成奇数堆石子；
否则，取走一整堆石子（因为此时每一堆石子数量均为奇数）。
由此可见，无论Alice如何操作，场上的偶数石子堆的数量一直减少，因而无法使得Bob无法操作。


*/