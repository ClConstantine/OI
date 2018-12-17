#include <iostream>
#include <cstdio>
#include <algorithm>
using std::cin;using std::cout;using std::cerr;using std::endl;
long long ans[1000010];
bool bo=0;
int main(){
	std::ios::sync_with_stdio(false);
    cout.tie(0);
    freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
		cin>>ans[i];
    }
    std::sort(ans+1,ans+N+1);
	for(int i=N-1;i>=2;i--){
		if(ans[i]+ans[i-1]>ans[i+1]){
			cout<<ans[i]+ans[i-1]+ans[i+1];
			bo=1;
			break;
		}
	}
	if(!bo) cout<<0;
	return 0;
}

score 100
