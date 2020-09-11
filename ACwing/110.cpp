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

const int mmax = 2500;

struct cownode{
	int l,r;
}cow[mmax + 10];
struct m{
	int s,num;
}SPF[mmax + 10];

int C,L,ans = 0;

bool cmp1(cownode a,cownode b){
	if(a.l > b.l) return 1;
	return 0;
}

bool cmp2(m a,m b){
	if(a.s > b.s) return 1;
	return 0;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);


	cin>>C>>L;

	rep(i,1,C){
		cin>>cow[i].l>>cow[i].r;
	}

	std::sort(cow + 1, cow + C + 1,cmp1);

	rep(i,1,L){
		cin>>SPF[i].s>>SPF[i].num;
	}

	std::sort(SPF + 1,SPF + L + 1,cmp2);

	rep(i,1,C){
		int t = -1,k = -1;

		rep(j,1,L){
			if(SPF[j].s >= cow[i].l && SPF[j].s <= cow[i].r){
				if(SPF[j].s >= SPF[t].s && SPF[j].num >= k && SPF[j].num || (t == -1 && SPF[j].num) ){
					t = j;
					k = SPF[j].num;
				}
			}
			else if(SPF[j].s < cow[i].l){
				break;
			}
		}
		if(t != -1){
			SPF[t].num--;
			ans ++;
		}

	}

	cout<<ans;


	return 0;
}