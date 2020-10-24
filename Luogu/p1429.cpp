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
int n,temp[mmax + 10];
struct point
{
	double x,y;
}ovo[mmax + 10];

bool cmp(point a,point b){
	if(a.x < b.x) return 1;
	else if(a.x == b.x && a.y < b.y) return 1;
	return 0; 
}

double dis(int a,int b){
	return sqrt((ovo[a].x - ovo[b].x) * (ovo[a].x - ovo[b].x) + (ovo[a].y - ovo[b].y) * (ovo[a].y - ovo[b].y));
}

double merge(int l,int r){
	double tdis = 0x7f7f7f7f;
	if(l >= r) return tdis;
	if(l + 1 == r) return dis(l,r);

	int mid = (l + r) >> 1;
	tdis = std::min(merge(l,mid),merge(mid + 1,r));

	int t = 0;
	rep(i,l,r){
		if(std::fabs(ovo[i].x - ovo[mid].x) <= tdis){
			temp[++t] = i;
		}
	}

	rep(i,1,t){
		rep(j,i + 1,t){
			tdis = std::min(dis(temp[i],temp[j]),tdis);
		}
	}

	return tdis;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	rep(i,1,n){
		cin>>ovo[i].x>>ovo[i].y;
	}

	std::sort(ovo + 1,ovo + n + 1,cmp);

	printf("%.4lf\n",merge(1,n));


	return 0;
}