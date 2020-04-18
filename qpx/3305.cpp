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

const int mmax = 1e5;

int n,m,l,r,L,R;
int a[mmax + 10];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	for(int i = 0;i < n;i++){
		cin>>a[i];
	}

	std::sort(a,a + n);

	cin>>m;

	while(m--){
		cin>>l>>r;
		if(l>r){
			int t = l;l = r;r = t;
		}

		L = std::lower_bound(a,a + n,l) - a;
		R = std::upper_bound(a,a + n,r) - a;

		cout<<R - L<<endl;
	}

	return 0;
}