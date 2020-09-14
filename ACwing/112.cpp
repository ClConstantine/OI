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

const int mmax = 1e3;

int n,ans = 0;
double d,pos = -0x7f7f7f7f;

struct build
{
	double x,y,l,r;
}ovo[mmax + 10];

bool cmp(build a,build b){
	if(a.l < b.l) return 1;
	return 0;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>d;

	rep(i,1,n){
		cin>>ovo[i].x>>ovo[i].y;

		if(ovo[i].y > d){
			cout<<-1;
			return 0;
		}
		
		double temp = sqrt(d * d - ovo[i].y * ovo[i].y);

		ovo[i].l = ovo[i].x - temp;
		ovo[i].r = ovo[i].x + temp;
	}

	std::sort(ovo + 1,ovo + 1 + n,cmp);


	rep(i,1,n){
		if(ovo[i].l > pos){
			pos = ovo[i].r;
			ans++;
		}
		else pos = std::min(ovo[i].r,pos);
	}

	cout<<ans;


	return 0;
}