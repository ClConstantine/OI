#include <iostream>
#include <cstdio>

using std::cin;using std::cout;using std::endl;using std::cerr;

const int mmax = 1000;const long long mod = 998244353;
char ovo[mmax + 10][mmax + 10];
bool f[mmax + 10][mmax + 10],flag;
long long vec[mmax * mmax + 10];
long long n,m,k,ans = 0;

long long dfs(int x,int y,int lx,int ly){
	if(ovo[x][y] == 'X' || x > n || y > m || x < 1 || y < 1 || flag){
		return 0;
	}

	if(f[x][y]){
		flag = 1;
		return 0;
	}

	f[x][y] = 1;
    
    long long t = 1;

    if(lx == x - 1 && ly == y){
        (t += dfs(x,y + 1,x,y) + dfs(x,y - 1,x,y) + dfs(x + 1,y,x,y)) %= mod;
    }
    else if(lx == x + 1 && ly == y){
        (t += dfs(x,y + 1,x,y) + dfs(x,y - 1,x,y) + dfs(x - 1,y,x,y)) %= mod;
    }
    else if(lx == x && ly == y - 1){
        (t += dfs(x,y + 1,x,y) + dfs(x + 1,y,x,y) + dfs(x - 1,y,x,y)) %= mod;
    }
    else if(lx == x && ly == y + 1){
        (t += dfs(x,y - 1,x,y) + dfs(x + 1,y,x,y) + dfs(x - 1,y,x,y)) %= mod;
    }
    else{
        (t += dfs(x,y + 1,x,y) + dfs(x,y - 1,x,y) + dfs(x + 1,y,x,y) + dfs(x - 1,y,x,y)) %= mod;
    }
	return t;
}

long long qp(long long a,long long b){
	long long temp = 1;
	while(b){
		if(b & 1) (temp *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return temp;
}

int main(){
	
	std::ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m>>k;

	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= m;++j){
			cin>>ovo[i][j];
		}
	}

	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= m;++j){
			if(f[i][j] || ovo[i][j] == 'X' || flag) continue;
			vec[++vec[0]] = dfs(i,j,-1,-1);
            //cout<<vec[vec[0]]<<' '<<flag<<endl;
		}
	}

	if(flag){
		cout<<0;
		return 0;
	}

	for(int i = 1;i <= vec[0];++i){
		(ans *= (k * qp(k - 1,vec[i] - 1)) % mod) %= mod;
	}

	cout<<ans;

	return 0;
}