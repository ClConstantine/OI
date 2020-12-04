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

const double del = 1e-7;
double l,r,mid,lmid,rmid,lnum,rnum,a[20];
int n;

double get(double y){
	double temp = 1;
	double tempans = a[0];
	rep(i,1,n){
		temp *= y;
		tempans += a[i] * temp;
	}
	return tempans;
}

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>l>>r;

	per(i,n,0){
		cin>>a[i];
	}

	while(r - l > del){
		mid = (l + r) / 2;
		lmid = (l + mid) / 2;
		rmid = (r + mid) / 2;

		lnum = get(lmid);
		rnum = get(rmid);

		if(0 < rnum - lnum){
			l = lmid;
		}
		else {
			r = rmid;
		}
	}

	printf("%.5lf\n",r);

	return 0;
}