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

const int mmax = 2e5;
int n,k;
int ovo[mmax + 10];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>ovo[i];
	}
	for(int i = k + 1;i <= n;i++){
		if(ovo[i]>ovo[i - k]) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}



	return 0;
}