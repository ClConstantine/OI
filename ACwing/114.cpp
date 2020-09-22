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

const int nmax = 1e3,mmax = 1e7;

int n;

struct node
{
	int a,b;
}ovo[nmax + 10];

int a[mmax + 10],b[mmax + 10],c[mmax + 10];

bool cmp(node x,node y){
	if(x.a * x.b < y.a * y.b) return 1;
	return 0;
}

void get(int x){
	while(x){
		a[0]++;
		a[a[0]] = x % 10;
		x /= 10;
	}	
} 

void mul(int x){
	rep(i,1,a[0]){
		a[i] *= x;
	}
	rep(i,1,a[0] - 1){
		if(a[i] > 9){
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
	}
	while(a[a[0]] > 9){
		a[0]++;
		a[a[0]] = a[a[0] - 1] / 10;
		a[a[0] - 1] %= 10;
	}
}

bool compare(){
	if(b[0] > c[0]) return 1;
	
	per(i,b[0],1){
		if(b[i] > c[i]) return 1;
	}

	return 0;
}

void div(int x){
	int t = 0;
	
	per(i,a[0],1){
		t += a[i];
		b[i] = t / x;
		t %= x;
		t *= 10;
	}

	b[0] = a[0];
	while(!b[b[0]] && b[0]){
		b[0]--;
	}

	if(compare()){
		rep(i,0,b[0]){
			c[i] = b[i];
		}
	}
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	rep(i,0,n){
		cin>>ovo[i].a>>ovo[i].b;
	}

	std::sort(ovo + 1,ovo + 1 + n,cmp);

	get(ovo[0].a);

	rep(i,1,n){
		div(ovo[i].b);
		if(ovo[i].a != 1) mul(ovo[i].a);
	}

	per(i,c[0],1){
		cout<<c[i];
	}




	return 0;
}