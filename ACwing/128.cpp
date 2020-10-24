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

const int mmax = 1e6;

int st1[mmax + 10],st2[mmax + 10],h1 = 0,h2 = 0;
int sum[mmax + 10],f[mmax + 10];
int q,num;
char opt;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>q;
	while(q--){
		cin>>opt;

		sum[0] = 0;
		f[0] = -0x7f7f7f7f;
		
		switch(opt){
			case 'I':
				cin>>num;
				st1[++h1] = num; 
				sum[h1] = sum[h1 - 1] + st1[h1];
				f[h1] = std::max(f[h1 - 1],sum[h1]);
			break;

			case 'D':
				if(h1) h1--;
			break;
			
			case 'L':
				if(h1) st2[++h2] = st1[h1--];
			break;

			case 'R':
				if(h2) st1[++h1] = st2[h2--];
				sum[h1] = sum[h1 - 1] + st1[h1];
				f[h1] = std::max(f[h1 - 1],sum[h1]);
			break;

			case 'Q':
				cin>>num;
				cout<<f[num]<<endl;
			break;

		}
	}


	return 0;
}