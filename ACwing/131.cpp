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
long long n,h[mmax + 10],a[mmax + 10],ans,m,t[mmax + 10];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	while(cin>>n && n){
		ans = 0;
		m = 0;
		memset(h,0,sizeof(h));
		memset(t,0,sizeof(t));

		rep(i,1,n){
			cin>>a[i];
		}
		a[n + 1] = 0;
		
		rep(i,1,n + 1){
			if(m == 0 || h[m] < a[i]){
				h[++m] = a[i];
				t[m] = 1;
			}
			else{
				long long width = 0;
				while(m  && h[m] > a[i]){
					width = width + t[m];
					ans = std::max(width * h[m],ans);
					m--;
				}
				h[++m] = a[i];
				t[m] = width + 1;
			}
			// cout<<"m "<<m<<" hm "<<h[m]<<" tm "<<t[m]<<" ans "<<ans<<endl;
		}
		cout<<ans<<endl;
	}



	return 0;
}