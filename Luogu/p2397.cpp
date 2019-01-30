#include<iostream>
#include<cstdio>

using std::cin;using std::cout;using std::cerr;using std::endl;

int N;
int fl,temp,now;

int main(){
	
	cin.tie(0);
	std::ios::sync_with_stdio(false);
	
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>temp;
		if(fl==0){
			now=temp;
			fl++;
		}
		else if(temp==now) fl++;
		else fl--;
		if(fl>N/2+1) break;
	}
	cout<<now;
	return 0;
} 
