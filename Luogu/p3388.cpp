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

const int nmax = 2e4,mmax = 1e5;

int next[2 * mmax + 10],head[nmax + 10],ver[2 * mmax + 10],dfn[nmax + 10],low[nmax + 10];
bool iscut[nmax + 10];
int tot = 0,idx = 0,n,m,x,y,num = 0;

void add(int x,int y){
	next[++tot] = head[x];
	head[x] = tot;
	ver[tot] = y;
}

void tarjan(int x,int fa){
	dfn[x] = low[x] = ++idx;
	
	int child = 0;
	
	for(int i = head[x];i;i = next[i]){
		int y = ver[i];
		
		if(!dfn[y]){
			tarjan(y,fa);
			low[x] = std::min(low[x],low[y]);

			if(low[y] >= dfn[x] && x != fa){
				iscut[x] = 1; 
			}
			if(x == fa) child++;
		}
		low[x] = std::min(low[x],dfn[y]);
	}
	if(fa == x && child >= 2){
		iscut[x] = 1;
	}
}


int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("P3388_1.in","r",stdin);

	cin>>n>>m;


	rep(i,1,m){
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}

	rep(i,1,n){
		if(!dfn[i])tarjan(i,i);
	}

	rep(i,1,n){
		if(iscut[i]) num++;
	}

	cout<<num<<endl;

	rep(i,1,n){
		if(iscut[i]) cout<<i<<' ';
	}
	return 0;
}