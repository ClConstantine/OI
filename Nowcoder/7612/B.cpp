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

char s[mmax + 10];int b[mmax + 10],n,ans,temp;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>(s + 1);

	bool f = 1;

	n = std::strlen(s + 1);

	rep(i,1,n){
		if(s[i] == '1') {
			if(f) temp++;
			b[i] = b[i - 1] + 1;
			ans = std::max(ans,b[i]);
		}
		else f = 0;
	}

	if(temp == n){
		cout<<temp;
		return 0;
	}

	ans =std::max(ans,b[n] + temp);
	cout<<ans;
	return 0;
}