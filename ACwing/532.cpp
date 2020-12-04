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

const int mmax = 100,tmax = 2500000;
int n,T,a[mmax + 10],m,t;
bool f[tmax + 10];

bool cmp(int a,int b){
	return a < b;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>T;

	while(T--){
		cin>>n;
		t = -1;
		m = n;
		memset(f,0,sizeof(f));

		rep(i,1,n){
			cin>>a[i];
			t = std::max(t,a[i]);
		}

		std::sort(a + 1,a + n + 1,cmp);
		
		f[0] = 1;

		rep(i,1,n){
			if(f[a[i]]){
				m--;continue;
			}
			for(int j = 0;a[i] + j <= t;j++){
				if(f[j]) f[a[i] + j] = 1;
			}
		}

		cout<<m<<endl;

	}


	return 0;
}