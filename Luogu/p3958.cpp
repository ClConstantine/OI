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

typedef long long ll;

const ll mmax = 1000;
ll T,n,r,h,x[mmax + 10],y[mmax + 10],z[mmax + 10];
ll fa[mmax + 10];
ll down,up; 
bool f1,f2;

ll getfa(ll m){
	if(fa[m] == m) return m;

	return fa[m] = getfa(fa[m]);
}

bool pue(ll m,ll n){
	if( sqrt( (x[n] - x[m]) * (x[n] - x[m]) + (y[n] - y[m]) * (y[n] - y[m]) + (z[n] - z[m]) * (z[n] - z[m]) ) <= (long double) 2 * r ){
		return 1;
	} 
	return 0;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>T;

	while(T--){
		cin>>n>>h>>r;
		up = down = 0;
		f1 = f2 = 0;
		
		for (int i = 1; i <= n; ++i)
		{
			fa[i] = i;
		}

		for(int i = 1;i <= n;++i){

			cin>>x[i]>>y[i]>>z[i];
			
			if(z[i] <= r) {
				if(!f1){
					down = i;					
				}
				else{
					fa[i] = down;
				} 
				f1 = 1;
			}
			if(z[i] + r >= h) {
				if(!f2){
					up = i;					
				}
				else{
					fa[i] = up;
				} 
				f2 = 1;
			}
		}

		if(!(f1 & f2)){
			cout<<"No"<<endl;
			continue;
		}

		for(int i = 1;i <= n;++i){
			for(int j = i + 1;j <= n;j++){
				if( pue(i,j) ) fa[getfa(i)] = getfa(j);
			}
		}

		if(getfa(down) == getfa(up)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}



	return 0;
}