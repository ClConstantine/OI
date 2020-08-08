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
typedef long long ll;

ll T,l,r,m;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>T;

	while(T--){
		cin>>l>>r>>m;
		
		ll del = r - l,a = l;

		while(a <= r){
			ll n = (m + del) / a;
			
			if(n > 0 && n * a >= m - del && n * a <= m + del){
				if(n * a <= m){
					cout<<a<<' '<<r<<' '<<r-(m - a * n)<<endl;
				}
				else cout<<a<<' '<<l<<' '<<l + a * n - m<<endl;
				break;
			}
			
			a++;
		}
	}


	return 0;
}