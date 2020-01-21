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

const int nmax = 2e4,mmax = 1e5;
int n,m,a,b,c,tot = 0,fa[nmax+10],en[nmax+10];

struct node{
	int x,y,z;
}con[mmax + 10];

bool cmp(node a,node b){
	if(a.z > b.z) return 1;
	return 0;
}

int get(int x){
	if(x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}

int main(){
	
	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	for(int i = 0;i < m;i++){
		cin>>a>>b>>c;
		con[++tot].x = a;
		con[tot].y = b;
		con[tot].z = c;
	}

	for(int i = 1;i <= n;i++){
		fa[i] = i;
	}

	std::sort(con+1,con+m+1,cmp);

	for(int i = 1;i <= m;i++){
		int t1 = get(con[i].x),t2 = get(con[i].y);
		if(t1==t2){
			cout<<con[i].z;
			return 0;
		}

		if(!en[con[i].x]){
			en[con[i].x] = con[i].y;
		}
		else{
			fa[get(en[con[i].x])] = t2; 
		}

		if(!en[con[i].y]){
			en[con[i].y] = con[i].x;
		}
		else{
			fa[get(en[con[i].y])] = t1;
		}

	}
	cout<<0;
	return 0;
}