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
const int mmax = 50;
long long amin,bmin;
long long n,ans,t;

struct gift
{
	long long a,b;
}ovo[mmax + 10];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>t;

	while(t--){
		cin>>n;
		ans = 0;
		amin = bmin = 1e9 + 10;

		rep(i,1,n){
			cin>>ovo[i].a;
			amin = std::min(amin,ovo[i].a);
		}
		rep(i,1,n){
			cin>>ovo[i].b;
			bmin = std::min(bmin,ovo[i].b);
		}

		rep(i,1,n){
			ans += std::max(ovo[i].a - amin,ovo[i].b - bmin);
		}
		cout<<ans<<endl;
	}


	return 0;
}