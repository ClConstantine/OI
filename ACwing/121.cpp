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

int n,c,l = 1,r = 1e4;
struct site
{
	int x,y;
}ovo[mmax + 10];

bool cmp(site a,site b){
	if(a.x < b.x) return 1;
	if(a.x == b.x && a.y < b.y) return 1;
	return 0;
}

bool check(int t){
	rep(i,1,n){
		int j = 1;
		while(j <= n && ovo[j].x - ovo[i].x < t){
			j++;
		}
		j--;

		if(j - i + 1 < c) continue;

		rep(k,i,j){
			int temp = 0;
			int ll = ovo[k].y,rr = ovo[k].y + t;
			rep(m,i,j){
				if(ovo[m].y >= ll && ovo[m].y < rr){
					temp ++;
				}
				if(temp >= c) return 1;
			}
		}
	}
	return 0;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>c>>n;
	rep(i,1,n){
		cin>>ovo[i].x>>ovo[i].y;
	}

	std::sort(ovo + 1, ovo + 1 + n,cmp);

	while(l < r){
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1; 
	}

	cout<<r;

	return 0;
}