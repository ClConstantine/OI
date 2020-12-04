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

const int mmax = 5e5;
int n,m,s,x,y,tot = 0;
int head[mmax + 10],next[2 * mmax + 10],ver[2 * mmax + 10];
int fa[mmax + 10][21],depth[mmax + 10];

void add(int x,int y){
	ver[++tot] = y;
	next[tot] = head[x];
	head[x] = tot;
}

void dfs(int cur,int facur){
	fa[cur][0] = facur;
	depth[cur] = depth[facur] + 1;
	// cout<<"cur "<<cur<<" "<<0<<" "<<fa[cur][0]<<endl;
	for(int i = 1;i <= (int)log2(depth[cur] - 1);++i){
		fa[cur][i] = fa[fa[cur][i - 1]][i - 1]; 
		// cout<<"cur "<<cur<<" "<<i<<" "<<fa[cur][i]<<endl;
	}
	for(int i = head[cur];i;i = next[i]){
		if(ver[i] != facur) dfs(ver[i],cur);
	}
}

int LCA(int x,int y){
	if(depth[x] < depth[y]){
		std::swap(x,y);
	}

	while(depth[x] > depth[y]){
		x = fa[x][(int)log2(depth[x] - depth[y])];
	}

	if(x == y) return x;
	
	int k;
	for(k = log2(depth[x] - 1);k >= 0;k--){
		if(fa[x][k] != fa[y][k]){
			x = fa[x][k],y = fa[y][k];
		}
	}
	return fa[x][0];
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m>>s;

	rep(i,1,n - 1){
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}

	dfs(s,0);
	rep(i,1,m){
		cin>>x>>y;
		cout<<LCA(x,y)<<endl;
	}

	return 0;
}