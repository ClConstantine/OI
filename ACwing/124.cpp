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

const int mmax = 1e7;

int base1,base2,n,len1,len2,temp;
std::map<int,char> s1;
std::map<char,int> s2;
int t1[mmax + 10],t2[mmax + 10];
char c1[mmax + 10];

int main(){

	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	rep(i,0,9){
		s1[i] = '0' + i;
		s2['0' + i] = i;
	}
	rep(i,0,25){
		s1[i + 10] = 'A' + i;
		s2['A' + i] = i + 10; 
	}
	rep(i,0,25){
		s1[i + 36] = 'a' + i;
		s2['a' + i] = i + 36;
	}

	rep(i,1,n){
		cin>>base1>>base2;
		cin>>(c1 + 1);
		len1 = std::strlen(c1 + 1);

		cout<<base1<<' '<<(c1 + 1)<<endl;
		cout<<base2<<' ';

		len2 = 0;

		rep(j,1,len1){
			t1[j] = s2[c1[j]]; 
		}

		// cout<<endl;
		// rep(i,1,len1){
		// 	cout<<t1[i];
		// }
		// cout<<endl<<endl;

		int k = 1;

		while(k <= len1){
			rep(j,k,len1 - 1){
				t1[j + 1] += (t1[j] % base2) * base1;
				t1[j] /= base2;
			}
			t2[++len2] = t1[len1] % base2;
			t1[len1] /= base2;

			// cout<<len2;
			// cout<<k;

			while(!t1[k] && k<= len1){
				k++;
			}
		}

		per(j,len2,1){
			cout<<s1[t2[j]];
		}

		cout<<endl<<endl;

	}



	return 0;
}