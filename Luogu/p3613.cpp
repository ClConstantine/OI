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

int n,i,j,k,q,p;

std::map<int,std::map<int,int> > chest;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>q;

	while(q--){
		cin>>p>>i>>j;
		if(p==1){
			cin>>k;
			chest[i][j] = k;
		}
		else{
			cout<<chest[i][j]<<endl;
		}
	}


	return 0;
}