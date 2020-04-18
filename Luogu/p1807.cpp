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

const int nmax = 1500,mmax = 5e4;
int n,m,t1,t2,t3,tot = 0;
int d[nmax + 10];
int head[nmax + 10],ver[mmax + 10],edge[mmax + 10],next[mmax + 10];
bool f[nmax + 10];

void add(int x,int y,int z){
	ver[++tot] = y;
	edge[tot] = z;
	next[tot] = head[x];
	head[x] = tot;
}

std::queue<int> q;

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	for(int i = 0;i < m;++i){
		cin>>t1>>t2>>t3;
		add(t1,t2,t3);
	}

	q.push(1);
	f[1] = 1;

	while(q.size()){
		int cur = q.front();
		q.pop();
		f[cur] = 0;
		for(int i = head[cur];i;i = next[i]){
			d[ver[i]] = std::max(d[cur]+edge[i],d[ver[i]]); 
			if(f[ver[i]]) continue;
			q.push(ver[i]);
			f[ver[i]] = 1;
		}
	}

	if(d[n] == 0){
		cout<<-1;
		return 0;
	}

	cout<<d[n];

	return 0;
}