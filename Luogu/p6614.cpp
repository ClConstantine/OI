#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using std::cin;using std::cout;using std::endl;using std::cerr;

typedef long long ll;

const ll kmax = 1e12,nmax = 1e5;
ll n,a,b;

struct node{
	ll x,y;
}ovo[nmax + 10];

bool cmp(node a,node b){
	if(a.x < b.x){
		return 1;
	}
	if(a.x == b.x && a.y > b.y){
		return 1;
	}
	return 0;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>a>>b;

	for(int i = 1;i <= n;++i){
		cin>>ovo[i].x>>ovo[i].y;
	}

	std::sort(ovo + 1,ovo + 1 + n,cmp);

	cout<<kmax<<' '<<ovo[n / (a + b) * a].x<<' '<<ovo[n / (a + b) * a].y;

	return 0;
}
