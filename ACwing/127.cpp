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

const int mmax = 1e5;

int n,m;
long long ans = 0,num = 0;
bool done[mmax + 10];

std::multiset<int> s;
std::multiset<int>::iterator it;

struct machine
{
	int x,y;
}a[mmax + 10],b[mmax + 10];

bool cmp(machine c,machine d){
	if(c.x > d.x) return 1;
	if(c.x == d.x && c.y > d.y) return 1;
	return 0;
}


int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	rep(i,1,n){
		cin>>a[i].x>>a[i].y;
	}
	rep(i,1,m){
		cin>>b[i].x>>b[i].y;
	}

	std::sort(a + 1,a + n + 1,cmp);
	std::sort(b + 1,b + m + 1,cmp);

	int i = 1,j = 1; 

	rep(i,1,m){
		while(j <= n){
			if(a[j].x < b[i].x){
				break;
			}
			s.insert(a[j].y);
			j++;
		}
		it = std::lower_bound(s.begin(),s.end(),b[i].y);
		if(it != s.end()) {
			num++;
			ans += b[i].x * 500 + b[i].y * 2;
			s.erase(it);
		}
	}

	
	cout<<num<<' '<<ans;

	return 0;
}