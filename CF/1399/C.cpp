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

const int mmax = 50;
int n,t,temp,ans,tempans;
std::map<int,int> ovo;
int a[mmax + 10];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>t;

	while(t--){
		cin>>n;
		ovo.clear();
		ans = 0;

		rep(i,1,n){
			cin>>temp;
			ovo[temp]++;
		}

		rep(k,2,2*n){
			tempans = 0;
			rep(i,1,n){
				if(2*i>k)break;
				else if(k - i > n) continue;
				else if(ovo[i] && i * 2 < k){
					tempans += std::min(ovo[i],ovo[k-i]);
				}
				else if(ovo[i]) tempans += ovo[i] / 2;
			}
			ans = std::max(tempans,ans);
		}

		cout<<ans<<endl;

	}



	return 0;
}