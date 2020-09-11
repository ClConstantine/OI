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

typedef long long ll;

const int mmax = 500;

int a[mmax * mmax + 10],b[mmax * mmax + 10];
int n,ans1,ans2,ans,t;
bool f;

void merge(int l,int r){
	if(l >= r) return ;

	int mid = (l + r) >> 1;
	int i = l,j = mid + 1;

	merge(l,mid);merge(mid + 1,r);

	rep(k,l,r){
		if(j > r || a[i] <= a[j] && i <= mid){
			b[k] = a[i]; 
			i++;
		}

		else{
			b[k] = a[j];
			j++;
			ans += mid + 1 - i;
		}
	}

	rep(k,l,r){
		a[k] = b[k]; 
	}
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	while(cin>>n && n != 0){
		ans = 0;f = 1;
		rep(i,1,n * n - 1){
			cin>>a[i];
			if(a[i] == 0) {i--;f = 0;}
		}
		if(f){
			cin>>t;
		}

		merge(1,n * n - 1);
		ans1 = ans;

		ans = 0;f = 1;
		rep(i,1,n * n - 1){
			cin>>a[i];
			if(a[i] == 0) {i--;f = 0;}
		}

		if(f){
			cin>>t;
		}

		merge(1,n * n - 1);
		ans2 = ans;

		if(!(std::abs(ans1 - ans2) % 2)){
			cout<<"TAK"<<endl;
		}
		else{
			cout<<"NIE"<<endl;
		}
		
	}



	return 0;
}