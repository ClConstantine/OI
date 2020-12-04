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

const int mmax = 5000;
long long a[mmax + 10],pre[mmax + 10];
int type,n;
long long f[mmax + 10],sum[mmax + 10];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>type;

	rep(i,1,n){
		cin>>a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	memset(f,0x7f,sizeof(f));
	f[0] = 0;
	f[1] = a[1] * a[1];

	rep(i,2,n){
		rep(j,0,i - 1){
			if(sum[i] - sum[j] >= sum[j] - sum[pre[j]]){
				f[i] = std::min((sum[i] - sum[j]) * (sum[i] - sum[j]) + f[j],f[i]);
				pre[i] = j;
			}
		}
	}
	cout<<f[n];


	return 0;
}