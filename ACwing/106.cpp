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

std::vector<int> vec;

int T,m,x,temp,num;


void add(int x){
	int p = std::lower_bound(vec.begin(),vec.end(),x) - vec.begin();
	vec.insert(vec.begin() + p ,x);
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>T;

	while(T--){
		vec.clear();
		
		cin>>temp>>m;

		num = 0;

		cout<<temp<<' '<<m / 2 + 1<<endl;
		rep(i,1,m){
			cin>>x;
			add(x);
			if(i%2){
				cout<<vec[i / 2]<<' ';
				num++;
			}
			if(num % 10 == 0 && i % 2 && i != m){
				cout<<endl; 
			}
		}
		cout<<endl;
	}



	return 0;
}