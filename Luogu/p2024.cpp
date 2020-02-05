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

const int mmax = 5e4;

int fa[mmax * 3 + 10]; 
int n,k,opt,x,y,sum;

int get(int x){
	if(fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}

void mix(int x,int y){
	fa[get(x)] = get(y);
}

int main(){
	
	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>k;

	for(int i = 1;i <= 3 * mmax;i++){
		fa[i] = i;
	}


	for(int i = 1;i <= k;i++){
		cin>>opt>>x>>y;

		if(x>n||y>n){
			sum++;
			continue;
		}

		if(opt == 1){
			if(get(x+n) == get(y) || get(x+n*2) == get(y)){
				sum++;
				continue;
			}
			mix(x,y);
			mix(x + n,y + n);
			mix(x + 2 * n,y + 2 * n);
		}
		else{
			if(get(x)==get(y) || get(x)==get(y+2*n)){
				sum++;
				continue;
			}
			mix(x,y + n);
			mix(x + n,y + 2 * n);
			mix(x + 2 * n,y);
		}
	}
	cout<<sum;
	return 0;
}