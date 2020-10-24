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

const int mmax = 1e8,t = 6e4;

int big[mmax + 10],prime[2 * t + 10],n;

void mul(int x){
	rep(i,1,big[0]){
		big[i] *= x;
	}
	rep(i,1,big[0] - 1){
		big[i + 1] += big[i] / 100;
		big[i] %= 100;
	}
	while(big[big[0]] > 99){
		big[big[0] + 1] = big[big[0]] / 100;
		big[big[0]] %= 100;
		big[0]++;
	}

	// cout<<x<<" mul "<<endl;
	// per(i,big[0],1){
	// 	cout<<big[i];
	// }
	// cout<<endl;
}

// void divide(int x){
// 	per(i,big[0],1){
// 		if(big[i] < x){
// 			big[i - 1] += big[i] * 10;
// 			big[i] = 0;
// 		}
// 		else if(big[i] % x){
// 			big[i - 1] += (big[i] % x) * 10;
// 		}
// 		big[i] /= x;
// 	}

// 	while(!big[big[0]]) big[0]--;

// 	// cout<<x<<" divide "<<endl;
// 	// per(i,big[0],1){
// 	// 	cout<<big[i];
// 	// }
// 	// cout<<endl;
// }

void print(int x){
	if(x < 10) printf("0");
	printf("%d",x);
}

void getpr(int x,int opt){
	int t = x;

	for(int i = 2;i * i <= t;i++){
		while(!(t % i)){
			prime[i] += opt;
			t /= i; 
		}
	}
	if(t) prime[t] += opt;
}


int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	big[0] = big[1] = 1;

	per(i,2*n,n + 2){
		getpr(i,1);
	}

	per(i,n,2){
		getpr(i,-1);
	}

	rep(i,2,2*n){
		while(prime[i]){
			mul(i);
			prime[i]--;
		}
	}

	printf("%d",big[big[0]]);
	per(i,big[0] - 1,1){
		print(big[i]);	
	}
	return 0;
}