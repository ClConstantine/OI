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

const int mmax = 500;
long long x,k,ovo[mmax + 10];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>k>>x;

	long long len = std::log10(x) + 1;

	ovo[k + 1] = 1;

	rep(i,1,len){
		bool f = 1;
		ovo[i] += x % 10;
		x /= 10;
		while(ovo[i] > 9){

			ovo[i + 1] += ovo[i] / 10;
			ovo[i] %= 10;

			if(f && i == len){
				len++;
				f = 0;
			}

		} 
	}
	
	len = std::max(len,k + 1ll);
	per(i,len,1){
		cout<<ovo[i];
	}

	return 0;
}