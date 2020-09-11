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


const int mmax = 5e5;
long long a[mmax + 10],b[mmax + 10],n,ans;

void merge(int l,int r){
	if(l >= r) return ;
	
	int mid = (l + r) >> 1;

	merge(l,mid);merge(mid + 1,r);

	int i = l,j = mid + 1;

	rep(k,l,r){
		if(j > r ||  a[i] <= a[j] && i <= mid){
			b[k] = a[i];
			i++;
		}
		else {
			b[k] = a[j];
			j++;
			ans += mid - i + 1;
		}
	}

	rep(k,l,r){
		a[k] = b[k];
	}

}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> n && n){
		
		ans = 0;

		rep(i,1,n){
			cin>>a[i];
		}

		merge(1,n);

		cout<<ans<<endl;

	}



	return 0;
}