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

std::map<std::string,int> chest;

int n,opt,s;
std::string t;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	while(n--){
		cin>>opt;

		if(opt == 1){
			cin>>t>>s;
			chest[t] = s;
			cout<<"OK"<<endl;
		}
		else if(opt == 2){
			cin>>t;
			if(chest.find(t) != chest.end()){
				cout<<chest[t]<<endl;
			}
			else{
				cout<<"Not found"<<endl;
			}
		}
		else if(opt == 3){
			cin>>t;
			if(chest.find(t) != chest.end()){
				chest.erase(t);
				cout<<"Deleted successfully"<<endl;
			}
			else{
				cout<<"Not found"<<endl;
			}
		}
		else
			cout<<chest.size()<<endl;
	}

	return 0;
}