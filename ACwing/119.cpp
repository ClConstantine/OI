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

typedef long long ll;
typedef long double ld;
const int mmax = 1e5;

int n,temp[mmax + 10],T;

struct node
{
	ld x,y;
	int id;	
}ovo[2 * mmax + 10];

bool cmp(node a,node b){
	if(a.x < b.x) return 1;
	else if(a.x == b.x && a.y < b.y) return 1;
	return 0;
}

ld dis(node a,node b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) *(a.y - b.y));
}

ld merge(int l,int r){
	ld tdis = 0x7f7f7f7f;
	if(l == r)return tdis;
	if(l + 1 == r){
		if(ovo[l].id ^ ovo[r].id)
			return dis(ovo[l],ovo[r]);
		else return tdis;
	}

	int mid = (l + r) >> 1;

	tdis = std::min(merge(l,mid),merge(mid + 1,r));

	int t = 0;

	rep(i,l,r){
		if(std::fabs(ovo[i].x - ovo[mid].x) <= tdis){
			temp[t++] = i;
		}
	}

	rep(i,1,t){
		rep(j,i + 1,t){
			if(ovo[i].id ^ ovo[j].id) tdis = std::min(tdis,dis(ovo[i],ovo[j]));
		}
	}

	return tdis;

}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>T;

	while(T--){
		cin>>n;
		rep(i,1,n){
			cin>>ovo[i].x>>ovo[i].y;
			ovo[i].id = 0;
		}
		rep(i,1,n){
			cin>>ovo[i + n].x>>ovo[i + n].y;
			ovo[i + n].id = 1;
		}
		std::sort(ovo + 1,ovo +n * 2 + 1,cmp);

		printf("%.3Lf\n",merge(1,2*n));
	}



	return 0;
}