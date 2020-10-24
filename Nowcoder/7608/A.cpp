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
int n,m,f[27],temp;
char c[51],ask;
struct node 
{	
	int sc,id;
	char n[55];
}g[27][mmax + 1];

bool cmp(node a,node b){
	if(a.sc > b.sc) return 1;
	else if(a.sc == b.sc && a.id < b.id){
		return 1;
	}	
	return 0;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	rep(i,1,n){
		cin>>c;
		int len = std::strlen(c);
		int x = c[len - 1] - 'a',y = ++f[c[len - 1] - 'a'];

		cin>>g[x][y].sc;
		g[x][y].id = i;
		std::strcpy(g[x][y].n,c);
	}

	rep(i,0,25){
		std::sort(g[i] + 1,g[i] + f[i] + 1,cmp);
	}

	while(m--){
		cin>>ask>>temp;
		int x = ask - 'a',y = f[ask - 'a'];
		if(y < temp) cout<<"Orz YYR tql"<<endl;
		else cout<<g[x][temp].n<<endl;
		// cout<<temp<<endl;
	}



	return 0;
}