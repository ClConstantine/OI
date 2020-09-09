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

const int mmax = 1e6;
int a[mmax + 10],que[mmax + 10],vis[mmax + 10];
int n,m,head,tail,ans = mmax + 10,num,ansa,ansb;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	rep(i,1,n){
		cin>>a[i];
	}

	que[1] = a[1];
	vis[a[1]] = 1;
	num = 1;

	head = 1;
	tail = 2;
	num = 1;
	ansa = 1;
	ansb = n;

	rep(i,2,n){
		while(vis[que[head]] != head){
			head++;
		}
		que[tail++] = a[i];
		if(!vis[a[i]]) num++;
		vis[a[i]] = i;
		
		if(num == m){
			if(tail - head < ans){
				ansa = head;
				ansb = tail - 1;
				ans = tail - head;
			}
			if(vis[que[head]] == head){
				vis[que[head]] = 0;
				num--;
			}
			head++;
		}
	}

	cout<<ansa<<' '<<ansb;


	return 0;
}