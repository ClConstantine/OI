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

const int mmax = 2e5;
int t,n,ans[mmax + 10],temp;
bool f;
char s[mmax + 10];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("test3.txt","r",stdin);

	cin>>t;

	while(t--){
		cin>>n;
		cin>>(s + 1);
		std::vector<int> st0,st1;
		temp = 0;

		rep(i,1,n){
			if(s[i] == '0'){
				if(!st1.empty()){
					ans[i] = *st1.begin();
					st0.push_back(*st1.begin());
					st1.erase(st1.begin());
				}
				else{
					ans[i] = ++temp;
					st0.push_back(temp);
				}
			}
			else{
				if(!st0.empty()){
					ans[i] = *st0.begin();
					st1.push_back(*st0.begin());
					st0.erase(st0.begin());
				}
				else{
					ans[i] = ++temp;
					st1.push_back(temp);
				}
			}
		}
		cout<<temp<<endl;
		rep(i,1,n){
			cout<<ans[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}