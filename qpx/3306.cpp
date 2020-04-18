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

const int mmax = 300;

int n,tot = 0,t,ans = 0;
int fa[mmax + 10];
struct s{
	int u,v,w;
}edge[2 * (mmax + 1) * (mmax + 1) + 10];

int getfather(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x] = getfather(fa[x]);
}

bool cmp(s a,s b){
	if(a.w < b.w) return 1;
	return 0;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;


	for(int i = 1;i <= n;++i){
		cin>>t;

		fa[i] = i;

		edge[++tot].u = 0;
		edge[tot].v = i;
		edge[tot].w = t;
	}

	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j){
			cin>>t;

			edge[++tot].u = i;
			edge[tot].v = j;
			edge[tot].w = t;

		}
	}

	std::sort(edge + 1,edge + tot + 1,cmp);

	for(int i = 1;i <= tot;i++){
		if(getfather(edge[i].u) != getfather(edge[i].v)){
			ans += edge[i].w;
			fa[getfather(edge[i].v)] = getfather(edge[i].u);
		}
	}

	cout<<ans;

	return 0;
}