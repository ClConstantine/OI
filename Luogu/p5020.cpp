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

const int mmax = 100,nmax = 25000;

int a[mmax + 10];
bool f[nmax + 10];
int n,max = 0,T,ans;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>T;

	while(T--){
		
		ans = 0;
		memset(f,0,sizeof(f));

		f[0] = 1;

		cin>>n;

		for(int i = 1;i <= n;++i){
			cin>>a[i];
			max = std::max(a[i],max);
		}

		std::sort(a + 1,a + n + 1);

		for(int i = 1;i <= n;i++){
			if(f[a[i]]){continue;}
			
			ans++;
			
			for(int j = 0;j + a[i] <= max;j++){
				if(f[j]) f[j + a[i]] = 1;
			}
		}
		cout<<ans<<endl;
	}


	return 0;
}