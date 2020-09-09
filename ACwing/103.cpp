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
#include <tr1/unordered_map>

using std::cin;using std::cout;using std::cerr;using std::endl;

#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = a;i >= b;--i)

const int mmax = 2e5;

int a[mmax + 10],b[mmax + 10],c[mmax + 10];

struct node
{
	int f1,f2,id;
}ovo[mmax + 10];

bool cmp2(node a,node b){
	if (a.f1 > b.f1) return 1;
	else if(a.f1 == b.f1 && a.f2 > b.f2){
		return 1;
	}
	return 0;
}

std::tr1::unordered_map<int,int> s;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;

	cin>>n;

	rep(i,1,n){
		cin>>a[i];
		s[a[i]] ++;
	}

	cin>>m;

	rep(i,1,m){
		cin>>b[i];
	}
	rep(i,1,m){
		cin>>c[i];
	}

	rep(i,1,m){
		ovo[i].id = i;
		ovo[i].f1 = s[b[i]];
		ovo[i].f2 = s[c[i]];
	}

	std::sort(ovo + 1,ovo + 1 + m,cmp2);

	cout<<ovo[1].id;

	return 0;
}