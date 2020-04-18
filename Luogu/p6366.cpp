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

const int mmax = 1e6;
bool ovo[mmax * 4 + 10],qaq[mmax * 4 + 10];
int n,ans1,ans2,ans = -1;
char c;

void build(int x,char c){
	int t;
	if(c >= '0' && c <= '9'){
		t = c - '0';
	}
	else{
		t = c - 'A' + 10;
	}
	for(int i = 4 * x;i >= 4 * x - 3;--i){
		ovo[i] = t % 2;
		qaq[i] = t % 2;
		t /= 2;
	}
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	while((c = getchar()) && c != '\n'){
		n++;
		build(n,c);
		//cout<<c<<endl;
	}

	int st = 1; 

	while(!ovo[st]){
		st++;
	}

	for(int i = st + 1;i <= 4 * n;++i){
		if(qaq[i - 1]){
			qaq[i - 1] ^= 1;
			qaq[i] ^= 1;
			qaq[i + 1] ^= 1;
			ans1++;
		}
	}

	ovo[st] ^= 1;
	ovo[st + 1] ^= 1;
	ans2++;

	for(int i = st + 1;i <= 4 * n;++i){
		if(ovo[i - 1]){
			ovo[i - 1] ^= 1;
			ovo[i] ^= 1;
			ovo[i + 1] ^= 1;
			ans2++;
		}
	}

	if(!qaq[4 * n]){
		ans = ans1;
		if(!ovo[4 * n]){
			ans = std::min(ans2,ans);
		}
	}
	else if(!ovo[4 * n]){
		ans = ans2;
	}
	//cout<<ans1<<' '<<ans2<<endl; 
	if(ans == -1){
		cout<<"No";
		return 0;
	}

	cout<<ans;
	return 0;
}