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

typedef std::pair<int,int> pii;

const int mmax = 1e5;
int n,a[mmax + 10],b[mmax + 10],now,nowf,ans;
std::priority_queue <pii> q;
int ansl[mmax + 10];
bool vis[mmax + 10],ma[mmax + 10];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	rep(i,1,n){
		cin>>a[i];
	}

	now = nowf = 1;

	q.push(std::make_pair(1 + a[1],1));
	vis[1] = 1;

	while(nowf < n + 1){
		int y = q.top().first,x = q.top().second;
		q.pop();

		if(y > n) break;

		if(y > nowf || (y >= nowf && x <= now)){

			// cout<<"now "<<now<<" nowf "<<nowf<<endl;

			now = x;
			nowf = y;
		}



		per(i,std::min(n,y),std::max(1,2 * x - y)){
			if(!vis[i]){
				vis[i] = 1;
				q.push(std::make_pair(i + a[i],i));
			}
		}

		if(q.empty() ) {

			ans++;
			ansl[ans] = now;
			a[now]++;
			nowf++;
			now = nowf;
			q.push(std::make_pair(now + a[now],now));
		}
	}

	cout<<ans<<endl;

	rep(i,1,ans - 1){
		cout<<ansl[i]<<' ';
	}
	if(ans) cout<<ansl[ans];



	return 0;
}
