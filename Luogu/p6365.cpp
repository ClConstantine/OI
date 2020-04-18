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

const int mmax = 1e6;
int n,mp = 0,mn;
int a[mmax + 10],b[mmax + 10];
std::map<ll,ll> s;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i]>>b[i];
		b[i] ^= a[i];
		if(a[i] == b[i]){
			s[a[i]]++;
		}
		else{
			s[a[i]]++;
			s[b[i]]++;
		}

		int sa = s[a[i]],sb = s[b[i]];

		if(sa > mn){
			mn = sa;
			mp = a[i];
		}
		if(sb > mn){
			mn = sb;
			mp = b[i];
		}

		if((sa == mn) && a[i] < mp){
			mp = a[i];
		}
		if((sb == mn) && b[i] < mp){
			mp = b[i];
		}
	}

	cout<<mp;

	return 0;
}