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

const int mmax = 5e5;
ll a[mmax + 10],b[mmax + 10],t,ans;
int n,m,k;

ll getnum(int l,int r){
	int i = l,j = r;
	ll num = 0;

	rep(k,l,r){
		b[k] = a[k];
	}

	std::sort(b + l,b + r + 1);

	while(j - i >= 1 && i - l < m){
		num += (b[j] - b[i]) * (b[j] - b[i]);
		j--;
		i++;
	}

	return num;
}

int multipy(int l){
	int r = l,p = 1;
	while(p){
		if(r + p <= n && getnum(l,r + p) <= t){
			r += p;
			p *= 2;
		}
		else p /= 2;
	}
	return r;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>k;

	while(k--){

		ans = 0;

		cin>>n>>m>>t;

		rep(i,1,n){
			cin>>a[i];
		}

		int arrow = 1;

		while(arrow <= n){
			arrow = multipy(arrow) + 1;
			ans ++;
		}

		cout<<ans<<endl;

	}



	return 0;
}
