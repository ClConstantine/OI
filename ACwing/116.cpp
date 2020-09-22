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

const int mmax = 4;

bool fri[mmax + 2][mmax + 2];
int x[mmax + 2],y[mmax + 2],s[mmax + 2][mmax + 2],pointans[mmax + 2][mmax + 2];
long long ans = 0x7f7f7f7f,step,tempstep;
char c;

void deal(long long f){
	int index = 1;

	while(f){
		if(f & 1) {
			tempstep ++;

			if(tempstep >  ans) return;

			x[(index - 1) / 4 + 1]++;
			y[(index - 1) % 4 + 1]++;
			s[(index - 1) / 4 + 1][(index - 1) % 4 + 1]++;
		}
		index ++;
		f >>= 1;
	}

	rep(i,1,4){
		rep(j,1,4){
			int temp = x[i] + y[j] + s[i][j];
			if((temp % 2) ^ fri[i][j]){
				return;
			}
		}
	}

	memset(pointans,0,sizeof(pointans));

	ans = tempstep;

	rep(i,1,4){
		rep(j,1,4){
			pointans[i][j] = s[i][j];
		}
	}

}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	rep(i,1,4){
		
		rep(j,1,4){
			cin>>c;
			if(c == '-') fri[i][j] = 0;
			else if(c == '+') fri[i][j] = 1;
		}
	}

	for(long long i=0;i < (1 << 16);i++){
		tempstep = 0;
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(s,0,sizeof(s));
		deal(i);
	}

	cout<<ans<<endl;

	rep(i,1,4){
		rep(j,1,4){
			if(pointans[i][j]) cout<<i<<' '<<j<<endl;
		}
	}



	return 0;
}