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

typedef unsigned long long ull;

const ull base1 = 109,base2 = 131;
const int mmax = 1500,nmax = 10000;
char c[mmax + 10];
int tot = 0,ans,n;

struct node {
	ull h1,h2;
}ovo[nmax + 10];


ull hash(char s[]){
	ull ans1 = 0,ans2 = 0;
	int len = std::strlen(s);
	rep(i,0,len - 1){
		ans1 = ans1 * base1 + (ull)s[i];
		ans2 = ans2 * base2 + (ull)s[i];
	}
	ovo[++tot].h1 = ans1;
	ovo[tot].h2 = ans2;
}

bool cmp(node a,node b){
	if(a.h1 < b.h1){
		return 1;
	}
	else if(a.h1 == b.h1 && a.h2 < b.h2){
		return 1;
	}
	return 0;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	rep(i,1,n){
		cin>>c;
		hash(c);
	}

	std::sort(ovo + 1,ovo + 1 + n,cmp);

	rep(i,1,n-1){
		if(ovo[i].h1 != ovo[i + 1].h1 || ovo[i].h2 != ovo[i + 1].h2){
			ans++;
		}
	}
	cout<<ans + 1;

	return 0;
}