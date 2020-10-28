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

const int mmax = 1e5;
char s[mmax + 10];
int T,t;
std::map<char,int> m;
int w[mmax +  10];

bool check1(int x){
	return((x & 1)?1:0);
}

bool check2(int x){
	return((x & 2)?1:0);
}

bool check3(int x){
	return((x & 4)?1:0);
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>T;

	while(T--){
		rep(i,0,25){
			cin>>t;
			m['a' + i] = t;
		}	

		cin>>s;
		int len = std::strlen(s);
		int f = 0,pos = 0;

		memset(w,0,sizeof(w));

		rep(i,0,len - 1){
			bool a = check1(m[s[i]]),b = check2(m[s[i]]);
			if(b){
				w[i] = 2;
			}
			else if(a){
				w[i] = 1;
			}
			else{
				f++;
				pos = i;
			}
		}

		if(w[0] == 0 || w[len - 1] == 0 || w[len - 1] == 1|| f > 1){
			cout<<"No"<<endl;
			continue;
		}
		else if(f == 1){
			if(w[pos - 1] == 2){
				cout<<"Yes"<<endl;
				continue;
			}
			cout<<"No"<<endl;
			continue;
		}
		else{
			bool d = 1;
			rep(i,1,len - 2){
				bool c = check3(m[s[i]]);
				if(c){
					if(w[i - 1] == 2){
						cout<<"Yes"<<endl;
						d = 0;
						break;
					}
				}
			}
			if(d){
				cout<<"No"<<endl;
			}
		}

	}




	return 0;
}