
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

const int mmax = 5e4;
int ans,n,a[mmax + 10];

struct node{
	int l,r,id;
}ovo[mmax + 10];

std::vector<int> vec;
std::vector<int> s;

bool cmp(node a,node b){
	if(a.l < b.l) return 1;
	return 0;
}

int add(int l,int r,int i){
	int lp = std::upper_bound(vec.begin(),vec.end(),-l) - vec.begin();
	int rp = std::upper_bound(vec.begin(),vec.end(),-r) - vec.begin();

	if(lp != vec.size()){
		a[i] = s[lp];

		s.erase(s.begin() + lp);
		s.insert(s.begin() + rp , a[i]);

		vec.erase(vec.begin() + lp);
		vec.insert(vec.begin() + rp , -r);

	}
	else {
		ans++;
		a[i] = ans;

		vec.insert(vec.begin() + rp,-r);
		s.insert(s.begin() + rp,ans);
	}

}	



int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	rep(i,1,n){
		cin>>ovo[i].l>>ovo[i].r;
		ovo[i].id = i;
	}

	std::sort(ovo + 1,ovo + 1 + n,cmp); 

	rep(i,1,n){
		add(ovo[i].l,ovo[i].r,ovo[i].id);
	}

	cout<<ans<<endl;

	rep(i,1,n){
		cout<<a[i]<<endl;
	}

	return 0;
}