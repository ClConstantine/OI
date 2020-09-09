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

typedef long long ll;

const int mmax = 1e5;

ll n,m,t,aver,ans;

struct shop
{
	ll x,y;
}ovo[mmax + 10];
ll a[mmax + 10],b[mmax + 10],s[mmax + 10];
bool f1 = 0,f2 = 0;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m>>t;


	rep(i,1,t){
		cin>>ovo[i].x>>ovo[i].y;
	}

	if(!(t % n)) f1 = 1;
	if(!(t % m)) f2 = 1;

	if(f1){
		if(f2){
			cout<<"both ";
		}
		else cout<<"row ";
	}
	else if(f2){
		cout<<"column ";
	}
	else cout<<"impossible ";

	ans = 0;

	if(f1){
		rep(i,1,t){
			a[ovo[i].x]++;
		}

		aver = t / n;
		s[0] = 0;
		
		rep(i,1,n){
			a[i] -= aver;
			s[i] = s[i - 1] + a[i];
		} 

		std::sort(s + 1,s + 1 + n);

		ll mid = s[n / 2 + 1];

		rep(i,1,n){
			ans += std::abs(mid - s[i]);
		}
	}

	if(f2){
		rep(i,1,t){
			b[ovo[i].y]++;
		}

		aver = t / m;
		s[0] = 0;
		
		rep(i,1,m){
			b[i] -= aver;
			s[i] = s[i - 1] + b[i];
		} 

		std::sort(s + 1,s + 1 + m);

		ll mid = s[m / 2 + 1];

		rep(i,1,m){
			ans += std::abs(mid - s[i]);
		}
	}

	if(f1 || f2){
		cout<<ans;
	}

	return 0;
}