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

const int mmax = 1000;

struct stu
{
	char team;
	int score;
}student[mmax + 10];

double ovo[30][mmax + 10];

bool cmp(stu a,stu b){
	if(a.score > b.score){
		return 1;
	}
	if(a.score == b.score){
		if(a.team < b.team){
			return 1; 
		}
	}
	return 0;
}

int main(){

	int n,k;

	cin>>n>>k;

	for(int i = 1;i <= n;++i){
		cin>>student[i].score>>student[i].team;
	}

	for(int i = 1;i <= k;++i){
		for(int j = 1;j <= k;++j){
			cin>>ovo[i][j];
			ovo[0][j] += ovo[i][j];
		}
	}

	for(int i = 1;i <= k;++i){
		ovo[26+1][i] = ovo[0][i] * 1.0 / k;
		ovo[0][i] = 0;
	}

	for(int i = 1;i <= k;++i){
		for(int j = 1;j <= k;++j){
			if(std::abs(ovo[26 + 1][j] - ovo[i][j]) <= 15){
				ovo[0][j] += ovo[i][j];
				ovo[26+2][j]++;
			}
		}
	}

	for(int i = 1;i <= k;++i){
		ovo[0][i] = int(ovo[0][i] * 1.0 / ovo[26+2][i] + 0.5);
	}


	for(int i = 1;i <= n;++i){
		student[i].score = (student[i].score * 0.6 + ovo[0][student[i].team - 'A' + 1] * 0.4 + 0.5);
	}

	std::sort(student + 1,student + n + 1,cmp);

	for(int i = 1;i <= n;++i){
		cout<<student[i].score<<' '<<student[i].team<<endl;
	}

	return 0;
}