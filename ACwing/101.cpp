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

const int mmax = 10000;
int n,p,h,m,a,b;
int ovo[mmax + 10];

int head[mmax + 10],next[mmax + 10],ver[mmax + 10];
int tot = 0;

void add(int x,int y){
	ver[++tot] = y;
	next[tot] = head[x];
	head[x] = tot;
}

bool ask(int a,int b){
	for(int i = head[a];i;i = next[i]){
		int y = ver[i];
		if(y == b){
			return 0;
		}
	}
	return 1;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>p>>h>>m;
	rep(i,1,m){
		cin>>a>>b;
		if(a > b){
			int t = a; a = b;b = t; 
		}

		if(!ask(a,b)){
			continue;
		}

		add(a,b);

		ovo[a + 1] --;
		ovo[b] ++;
	}

	rep(i,1,n){
		ovo[i] += ovo[i - 1];
		cout<<ovo[i] + h<<endl;
	}

	return 0;
}