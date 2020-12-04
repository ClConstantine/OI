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

const int mmax = 1e5;
long long l,r,ans,sum;
long long T,n,a[mmax + 10];
int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>T;

	while(T--){
		cin>>n;

		l = 1,r = n,ans = 0,sum = 0;

		rep(i,1,n){
			cin>>a[i];
			sum += a[i];
		}

		if(sum % n){
			cout<<-1<<endl;
			continue;
		}

		sum /= n;

		rep(i,1,n){
			ans += std::abs(sum - a[i]);
			a[i + 1] += a[i] - sum;			
		}
		
		cout<<ans<<endl;

	}



	return 0;
}