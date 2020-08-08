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

const int mmax = 50;
int a[mmax + 10];
int t,n;
bool f;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>t;

	while(t--){
		cin>>n;
		f = 0;
		rep(i,1,n){
			cin>>a[i];
		}

		std::sort(a + 1,a + n + 1);

		rep(i,1,n - 1){
			if(a[i + 1] - a[i] > 1){
				f = 1;
				cout<<"NO"<<endl;
				break;
			}
		}
		if(!f){
			cout<<"YES"<<endl;
		}
	}



	return 0;
}