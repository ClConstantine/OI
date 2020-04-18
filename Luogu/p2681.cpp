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
#include <tr1/unordered_map>

using std::cin;using std::cout;using std::cerr;using std::endl;

const int mmax = 1000;
int n,m,f,l,r;
int ovo[mmax + 10];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	for(int i = 1;i <= n;++i){
		cin>>ovo[i];
	}

	while(m--){
		cin>>f>>l>>r;
		
		if(f){
			ovo[l] = r;
		}
		else{
			std::tr1::unordered_map <int,int> s;
			int mn = 0,mp = 0;
			for(int i = l;i <= r;++i){
				s[ovo[i]]++;
				if(s[ovo[i]] > mn){
					mn = s[ovo[i]];
					mp = ovo[i];
				}
				else if(s[ovo[i]] == mn && ovo[i] < mp){
					mp = ovo[i];
				}
			}
			cout<<mp<<endl;
		}
	}
	return 0;
}