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

const int mmax = 1e4; 
int fa[2*mmax + 10];
int n,m,p,q,a,b,t;

int get(int x){
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}

int main(){

	cin.tie(0);
	std::ios::sync_with_stdio(0);

	cin>>n>>m>>p>>q;

	for(int i = 0;i <=2*mmax ; i++){
		fa[i] = i;
	}

	for(int i = 0;i < p;i++){
		cin>>a>>b;
		/*if(a > b){
			t = a;
			a = b;
			b = t;
		}*/
		fa[get(b + mmax)] = get(a + mmax); 
	}

	for(int i = 0;i < q;i++){
		cin>>a>>b;
		/*if(a < b){
			t = a;
			a = b;
			b = t;
		}*/
		fa[get(b + mmax)] = get(a + mmax); 
	}

	a=b=0;
	
	for(int i =0;i <= 2*mmax;i++){
		if(i<mmax){
			if(get(fa[i]) == get(fa[mmax-1])) a++;
		}

		else if (i>mmax){
			if(get(fa[i]) == get(fa[mmax+1])) b++;
		}
	}
	//cout<<a<<' '<<b<<endl;
	cout<<std::min(a,b);

	return 0;
}