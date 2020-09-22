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

std::map<char,int> s;
int ans = 0,st[15][15],num[15];
int cnt = 0,card;
char c = 0;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	rep(i,2,9){
		s['0' + i] = i;
	}
	s['0'] = 10;
	s['J'] = 11;
	s['Q'] = 12;
	s['K'] = 13;
	s['A'] = 1;

	rep(i,1,13){
		st[i][0] = 0;
		// cout<<i<<" ";
		rep(j,1,4){
			cin>>c;
			st[i][4 - (st[i][0]++)] = s[c];
			// cout<<s[c]<<' ';
		}
		// cout<<endl;
	}
	card = 13;

	while(cnt < 1e7){
		cnt++;
		if(card == 13){
			if(st[13][0] == 0) break;
			card = st[13][st[13][0]];
			st[13][0]--;
			num[card]++;
		}
		else{
			st[card][++st[card][0]] = card;
			card = st[card][st[card][0] - 4];
			num[card]++;
			if(st[card][0] > 1e5) break;
		}

		// cout<<card<<endl;
	}



	rep(i,1,12){
		if(num[i] >= 4){
			ans++;
		}
	}

	cout<<ans;

	return 0;
}