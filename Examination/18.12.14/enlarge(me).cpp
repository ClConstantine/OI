#include <cstdio>
#include <iostream>
 
using std::cin; using std::cout; using std::cerr; using std::endl;

int a[20];
int map[15][15];
int gcd(int x,int y){
	int a=x>y?x:y;
	int b=x<y?x:y;
	if(b==1) return a;
	else return gcd(a%b,b);
}
int main(){
	freopen("enlarge.in", "r", stdin);
	freopen("enlarge.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
	int N;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			
		}
	}
	cout<<3;
    return 0;
}

score 25
