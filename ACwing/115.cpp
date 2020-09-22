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

const int mmax = 1e3;
int n,r,u,v,ans = 0;
struct node
{
	int fa,mergenum;
	double w,a;
}ovo[mmax + 10];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>r;

	rep(i,1,n){
		cin>>ovo[i].a;
		ovo[i].w = ovo[i].a;
		ovo[i].mergenum = 1;
	}
	rep(i,1,n){
		cin>>u>>v;
		ovo[v].fa = u;
	}

	rep(i,1,n - 1){
		int now;
		double aver = 0;
		
		rep(j,1,n){
			if(j != r && aver < ovo[j].w){
				aver = ovo[j].w;
				now = j;
			}
		}
		int father = ovo[now].fa;

		ans += ovo[now].a * ovo[father].mergenum;
		
		ovo[now].w = -1;
		ovo[father].mergenum += ovo[now].mergenum;
		ovo[father].a += ovo[now].a;
		ovo[father].w = ovo[father].a / ovo[father].mergenum;
 
		rep(i,1,n){
			if(ovo[i].fa == now){
				ovo[i].fa = father;
			}
		}
	}

	cout<<int(ans + ovo[r].a);


	return 0;
}